#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>

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

void  sortType(vector<Poker> (&rank)[5], Poker& set) {

  
}

// #include <map>

// string checkPattern(const string& str) {
//     map<char, int> freq;
//     for (char c : str) {
//         freq[c]++;
//     }

//     int five = 0, four = 0, three = 0, two = 0;
//     for (auto& [key, value] : freq) {
//         if (value == 5) five++;
//         else if (value == 4) four++;
//         else if (value == 3) three++;
//         else if (value == 2) two++;
//     }

//     if (five == 1) return "5 same char";
//     else if (four == 1) return "4 same char";
//     else if (three == 1 && two == 1) return "3 same + 2 same";
//     else if (two == 2) return "2 pair of same char";
//     else return "No pattern found";
// }

int main(int argc, char** argv) {

  std::ifstream input("input");
  int sum = 0;
  vector<Poker> rank[5];

  vector<Poker> poke = makePokerVec(input);
  for (auto it = poke.begin(); it != poke.end(); it++){
    cout << it->hand << " " << it->bid << endl;
  }

  return (0);
}
