// Copyright 2014, Jens Hoffmann
//
// Euler problem 37 - Truncatable primes
//
// The number 3797 has an interesting property. Being prime
// itself, it is possible to continuously remove digits from
// left to right, and remain prime at each stage: 3797, 797,
// 97, and 7. Similarly we can work from right to left:
// 3797, 379, 37, and 3.
// 
// Find the sum of the only eleven primes that are both
// truncatable from left to right and right to left.
// 
// NOTE: 2, 3, 5, and 7 are not considered to be truncatable
// primes.
//
#include <stdio.h>
#include <map>
#include "../prime.h"


bool isTruncatablePrime(int n) {
  int operand = 1;
  int n2 = n;
  while (n2) {
    operand *= 10;
    n2 /= 10;
  }
  operand /= 10;
  while (operand >= 10) {
    if (!utils::isPrime(n % operand) || !utils::isPrime(n / operand)) {
      return false;
    }
    operand /= 10;
  }
  if (!utils::isPrime(n)) {
    return false;
  }
  return true;
}

int main() {
  int i = 8;
  int count = 0;
  int sum = 0;
  while (count != 11) {
    if (isTruncatablePrime(i)) {
      printf("%d is truncatable prime\n", i);
      sum += i;
      count += 1;
    }
    i += 1;
  }
  printf("The sum of all 11 truncatable primes is %d\n", sum);
  return 0;
}
