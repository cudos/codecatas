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
#include <stdio.h>


int main() {
  int result = 0;
  for (int i = 1; i <= 999999999; ++i) {
    if (isPandigital(i) && isPrime(i)) {
      result = i;
    }
  }
  printf("%d\n", result);
  return 0;
}
