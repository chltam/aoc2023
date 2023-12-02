#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>

std::vector<std::string> makeVec(std::string& full, char delim) {
  std::istringstream iss(full);
  std::vector<std::string> vec;
  std::string line;
  while (std::getline(iss, line, delim)) {
    vec.push_back(line);
  }
  return vec;
}

bool checkGame(std::string& game) {
  std::vector<std::string> draws = makeVec(game, ';');  
  for (std::string& draw : draws) {
    std::cout << draw << std::endl;
    auto pick = makeVec(draw, ',');
    for (auto it = pick.begin(); it != pick.end(); it++) {
      std::istringstream iss(*it);
      int n;
      std::string color;
      iss >> n >> color;
      std::cout << color << n << std::endl;
      if (color == "red" && n > 12) return false;
      if (color == "green" && n > 13) return false;
      if (color == "blue" && n > 14) return false;
    }
  }
  return (true);
}

int main(int argc, char** argv) {
  

  std::ifstream input("input");
  std::vector<std::string> games;
  std::string line;
  int sum = 0;

  while (std::getline(input, line)) {
    games.push_back(line.substr(line.find(':') + 2));
  }
  for (int i = 0; i < 100; i++) {
    std::cout << "game: " << games[i] << std::endl;
    if (checkGame(games[i]))
      sum += i + 1;
  }
  std::cout << sum << std::endl;
  input.close();
  return (0);
}
