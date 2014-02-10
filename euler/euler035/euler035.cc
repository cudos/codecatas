// Copyright 2014, Jens Hoffmann
//
// Euler problem 35 - Circular primes
//
// The number, 197, is called a circular prime because all rotations of the
// digits: 197, 971, and 719, are themselves prime.
//
// There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37,
// 71, 73, 79, and 97.
//
// How many circular primes are there below one million?
//
#include <stdio.h>
#include "../prime.h"

int main() {
  int count = 1;
  for (int x = 3; x < 1000*1000; x += 2) {
    int x2 = x;
    bool isCircularPrime = true;
    int k = 0;
    while (x2) {
      x2 /= 10;
      k += 1;
    }
    x2 = x;
    do {
      if (!utils::isPrime(x2)) {
        isCircularPrime = false;
        break;
      }
      int xc = x2 % 10;
      x2 /= 10;
      int xr = 0;
      while (x2) {
        xr *= 10;
        xr += x2 % 10;
        x2 /= 10;
      }
      int k2 = k;
      while (k2 - 1) {
        xc *= 10;
        xc += xr % 10;
        xr /= 10;
        k2 -= 1;
      }
      x2 = xc;
    } while (x2 != x);
    if (isCircularPrime) {
      printf("%d is circular prime\n", x);
      count += 1;
    }
  }
  printf("\n");
  printf("There are %d circular primes below one million.\n", count);

  return 0;
}
