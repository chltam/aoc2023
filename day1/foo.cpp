#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <algorithm>

int getNumber(std::string line) {
  std::string number[] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
  };
  int first, last;
  int findex = 999;
  int lindex = 0;
  for (int i = 1; i < 10; i++) {
    int pos = line.find(number[i]);
    if (pos == line.npos) continue;
    if (pos < findex) {
      findex = pos;
      first = i;
    }
  }
  for (int i = 1; i < 10; i++) {
    int pos = line.rfind(number[i]);
    if (pos == line.npos) continue;
    if (pos > lindex) {
      lindex = pos;
      last = i;
    }
  }
  for (int i = 0; line[i]; i++) {
    if (isdigit(line[i]) && i < findex) {
      first = line[i] - '0';
      break ;
    }
  }
  for (int i = 0; line[i]; i++) {
    if (isdigit(line[i]) && i >= lindex) {
      last = line[i] - '0';
      lindex = i;
    }
  }
  return (first * 10 + last);
}

int main(int argc, char** argv) {
  

  std::ifstream input("input");
  std::string line;
  int sum = 0;
  while (getline(input, line)) {
    int first, last;
    std::cout << line << std::endl;
    sum += getNumber(line);
    
  }
  input.close();
  std::cout << sum << std::endl;
  return (0);
}
