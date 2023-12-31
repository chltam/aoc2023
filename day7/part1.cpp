#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

std::vector<std::string> makeVec(std::string& full, char delim) {
  std::istringstream iss(full);
  std::vector<std::string> vec;
  std::string line;
  while (std::getline(iss, line, delim)) {
    vec.push_back(line);
  }
  return vec;
}


struct Poker {
  string hand;
  int bid;
};

vector<Poker> makePokerVec(ifstream& input) {
  vector<Poker> poke;
  string buffer;
  while (getline(input, buffer)) {
    istringstream iss(buffer);
    string hand;
    int bid;
    iss >> hand >> bid;
    poke.push_back({hand, bid});
  }
  return poke;
}

void  sortType(vector<Poker> (&rank)[7], Poker& set) {
  map<char, int> freq;
  for (char c: set.hand)
    freq[c]++;
  int five = 0, four = 0, three = 0, two = 0;
  for (auto& [key, value] : freq) {
    if (value == 5) five++;
    else if (value == 4) four++;
    else if (value == 3) three++;
    else if (value == 2) two++;
  }
  if (five == 1)
    rank[6].push_back(set);
  else if (four == 1)
    rank[5].push_back(set);
  else if (three == 1 && two == 1)
    rank[4].push_back(set);
  else if (three == 1 && two == 0)
    rank[3].push_back(set);
  else if (two == 2)
    rank[2].push_back(set);
  else if (two == 1)
    rank[1].push_back(set);
  else
    rank[0].push_back(set);
}

bool  compare(Poker& x, Poker& y) {
  string order = "123456789TJQK";
  for (size_t i = 0; i < 5; i++) {
    if (order.find(x.hand[i]) != order.find(y.hand[i]))
      return order.find(x.hand[i]) < order.find(y.hand[i]);
  }
  return true;
  
}

int main(int argc, char** argv) {

  std::ifstream input("input");
  int sum = 0;
  vector<Poker> rank[7];

  vector<Poker> poke = makePokerVec(input);
  for (auto it = poke.begin(); it != poke.end(); it++){
    sortType(rank, *it);
  }
  for (int i = 0; i < 7; i++) {
    sort(rank[i].begin(), rank[i].end(), compare);
  }
  int multi = 1;
  for (int i = 0; i < 7; i++) {
    for (auto it = rank[i].begin(); it != rank[i].end(); it++)
      sum += it->bid * multi++;
  }

  cout << "sum: " << sum << endl;

  return (0);
}
