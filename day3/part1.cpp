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

int main(int argc, char** argv) {
  

  std::ifstream input("input");
  std::vector<std::string> schem;
  std::string line;
  int sum = 0;

  while (std::getline(input, line)) {
    schem.push_back(line);
  }
  for (int i = 0; i < schem.size(); i++) {
    int start = 0, end = 0;
    while (schem[i][start] ) {
      end = 0;
      while (schem[i][start] && !isdigit(schem[i][start]))
        start++;
      while (isdigit(schem[i][start + end]))
        end++;
      if ((i > 0 && valid(schem[i - 1], start, start + end)) ||
          valid(schem[i], start, start + end) ||
          (i < schem.size() - 1 && valid(schem[i + 1], start, start + end))) {
            // cout << schem[i].substr(start, end) << " yes" << endl;
            sum += stoi(schem[i].substr(start, end));
          }
      // cout << "start: " << start << " end: " << end << endl;
      // cout << schem[i].substr(start - 1, end - start + 1) << endl;
      
      start += end;
    }
    // cout << schem[i] << endl;

  }

  input.close();
  std::cout << sum << std::endl;
  return (0);
}
