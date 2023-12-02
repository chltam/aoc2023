#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>

struct cube {
  cube() : red(0), green(0), blue(0) {}
  int red;
  int green;
  int blue;
};

std::vector<std::string> makeVec(std::string& full, char delim) {
  std::istringstream iss(full);
  std::vector<std::string> vec;
  std::string line;
  while (std::getline(iss, line, delim)) {
    vec.push_back(line);
  }
  return vec;
}

cube checkGame(std::string& game) {
  cube min;
  std::vector<std::string> draws = makeVec(game, ';');  
  for (std::string& draw : draws) {
    std::cout << draw << std::endl;
    auto pick = makeVec(draw, ',');
    for (auto it = pick.begin(); it != pick.end(); it++) {
      std::istringstream iss(*it);
      int n;
      std::string color;
      iss >> n >> color;
      if (color == "red" && n > min.red) min.red = n;
      if (color == "green" && n > min.green) min.green = n;
      if (color == "blue" && n > min.blue) min.blue = n;
    }
  }
  return (min);
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
    cube min = checkGame(games[i]);
    sum += min.red * min.green * min.blue;
  }
  std::cout << sum << std::endl;
  input.close();
  return (0);
}
