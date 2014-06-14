// Copyright 2014, Jens Hoffmann
//
// Euler problem 43 - Sub-string divisibility
//
// The number, 1406357289, is a 0 to 9 pandigital number because it is made up
// of each of the digits 0 to 9 in some order, but it also has a rather
// interesting sub-string divisibility property.
//
// Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we
// note the following:
//
//     d2d3d4=406 is divisible by 2
//     d3d4d5=063 is divisible by 3
//     d4d5d6=635 is divisible by 5
//     d5d6d7=357 is divisible by 7
//     d6d7d8=572 is divisible by 11
//     d7d8d9=728 is divisible by 13
//     d8d9d10=289 is divisible by 17
//
// Find the sum of all 0 to 9 pandigital numbers with this property.
//
#include <stdio.h>
#include <vector>
#include "../utils.h"

int main() {
  long long result = 0;
  std::vector<long long> d = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<long long> div = {2, 3, 5, 7, 11, 13, 17};

  while (utils::nextPermutation(&d)) {
    bool hasProperty = true;
    for (size_t i = 1, j = 0; i < 8 && j < d.size(); ++i, ++j) {
      long long x = utils::concatenate<long long>(d.begin() + i, d.begin() + i + 2 + 1);
      if (x % div[j] != 0) {
        hasProperty = false;
        break;
      }
    }
    if (hasProperty) {
      result += utils::concatenate<long long>(d.begin(), d.end());
    }
  }
  printf("%lli\n", result);
  return 0;
}
