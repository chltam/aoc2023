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

bool valid(std::string& line, int start, int end) {
  if (start > 0)
    start -= 1;
  if (end < line.size() - 1)
    end += 1;
  cout << line.substr(start, end - start) << endl;
  // bool re = any_of(line.begin() + start, line.end() + end + 1, [](char c) {
  //   return !isdigit(c) && c != '.';
  // });
  // cout << re << endl;
  // return (re);
  for (int i = start; i < end; i++) {
    if (!isdigit(line[i]) && line[i] != '.')
      return true;
  }
  // cout << "false" << endl;
  return(false);
}

int fullNumber(string str, int start) {
  int rei = 0;
  while (start > 0 && isdigit(str[start]))
    start--;
  if (!isdigit(str[start]))
    start++;
  while (isdigit(str[start])) {
    rei = rei * 10 + str[start] - '0';
    start++;
  }
  return (rei);
}

int checkLine(string& line, int pos) {
  if (isdigit(line[pos]))
    return fullNumber(line, pos);
  return (0);
}

void  checkThree(string& line, int pos, vector<int>& vec) {
  int nb;

  if ((nb = checkLine(line, pos)) != 0) {
    vec.push_back(nb);
    return ;
  }
  if (pos > 0 && (nb = checkLine(line, pos - 1)) != 0) {
    vec.push_back(nb);
  }
  if (pos < line.size() - 1 && (nb = checkLine(line, pos + 1)) != 0) {
    vec.push_back(nb);
  }
}

int main(int argc, char** argv) {
  

  std::ifstream input("input");
  std::vector<std::string> schem;
  std::string line;
  long sum = 0;

  while (std::getline(input, line)) {
    schem.push_back(line);
  }
  for (int i = 0; i < schem.size(); i++) {
    int start = 0, end = 0;
    while (schem[i][start]) {
      vector<int> gear;
      if (schem[i][start] == '*') {
        if (i > 0)
          checkThree(schem[i - 1], start, gear);  
        checkThree(schem[i], start, gear);
        if (i < schem.size() - 1)
          checkThree(schem[i + 1], start, gear);
        if (gear.size() == 2) {
          sum += gear[0] * gear[1];
        }
        gear.clear();
        cout << "sum: " << sum << endl;
      }
      start++;
    }

  }


  input.close();
  std::cout << sum << std::endl;
  return (0);
}
