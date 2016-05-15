// Copyright 2014, Jens Hoffmann
// Euler Problem 18
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>


int findPath(
    const std::vector<std::vector<int>>& triangle,
    size_t i,
    size_t j) {
  if (i == triangle.size() - 1) {
    return triangle[i][j];
  }

  int left, right;
  left = right = triangle[i][j];

  left = triangle[i][j] + findPath(triangle, i + 1, j);
  right = triangle[i][j] + findPath(triangle, i + 1, j + 1);

  if (left > right) {
    return left;
  } else {
    return right;
  }
}


int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Usage: %s <file>\n", argv[0]);
    exit(1);
  }

  std::ifstream file(argv[1]);
  std::string line;
  std::string number;
  std::vector<std::vector<int>> triangle;

  while(std::getline(file, line)) {
    std::vector<int> row;
    number = "";
    line += " ";
    for (char ch : line) {
      if (ch == ' ') {
        row.push_back(atoi(number.c_str()));
        number = "";
        continue;
      }
      number += ch;
    }
    triangle.push_back(row);
  }

  int result = findPath(triangle, 0, 0);
  printf("%d\n", result);

  return 0;
}
