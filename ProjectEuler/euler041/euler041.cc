// Copyright 2014, Jens Hoffmann
//
// Euler problem 41 - Pandigital prime
//
// We shall say that an n-digit number is pandigital if it makes use of all the
// digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is
// also prime.
//
// What is the largest n-digit pandigital prime that exists?
//
#include <assert.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "../utils.h"
#include "../prime.h"


int main() {
  int result = 0;
  std::vector<int> numbers = {1};
  for (int d = 2; d < 8; ++d) {
    numbers.push_back(d);
    while (utils::nextPermutation(&numbers)) {
      int x = utils::concatenate(numbers.begin(), numbers.end());
      if (utils::isPrime(x)) {
        result = x;
      }
    }
  }
  printf("%d\n", result);
  return 0;
}
