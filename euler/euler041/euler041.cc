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
#include "../prime.h"


int concatenate(const std::vector<int>& arr) {
  int result = 0;
  for (const auto& el : arr) {
    int x = el;
    int xr;
    while (x) {
      xr *= 10;
      xr += x % 10;
      x /= 10;
    }
    while (xr) {
      result *= 10;
      result += xr % 10;
      xr /= 10;
    }
  }
  return result;
}

void swap(std::vector<int>* arr, size_t pos1, size_t pos2) {
  assert(pos1 < arr->size() && pos2 < arr->size());
  int tmp = (*arr)[pos1];
  (*arr)[pos1] = (*arr)[pos2];
  (*arr)[pos2] = tmp;
}

bool nextPermutation(std::vector<int>* arr) {
  assert(arr->size() > 1);
  size_t i1, i2;
  // Find the rightmost element that is the first in a pair in ascending order
  for (i1 = arr->size() - 2, i2 = arr->size() - 1; (*arr)[i1] >= (*arr)[i2] && i1 != 0;
      i1--, i2--);
  if ((*arr)[i1] >= (*arr)[i2]) {
    std::reverse(arr->begin(), arr->end());
    return false;
  } else {
    // Find the rightmost elements to the right of i1 that is greater than
    // arr[i1]
    for (i2 = arr->size() - 1; i2 > i1 && (*arr)[i2] <= (*arr)[i1]; i2--);
    // Swap it with the first one
    swap(arr, i1, i2);
    // Reverse the remainder
    std::reverse(arr->begin() + i1 + 1, arr->end());
  }
  return true;
}

int main() {
  int result = 0;
  std::vector<int> numbers = {1};
  for (int d = 2; d < 8; ++d) {
    numbers.push_back(d);
    while (nextPermutation(&numbers)) {
      int x = concatenate(numbers);
      if (utils::isPrime(x)) {
        result = x;
      }
    }
  }
  printf("%d\n", result);
  return 0;
}
