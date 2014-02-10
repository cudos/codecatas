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
#include <unordered_map>

std::unordered_map<int, bool> primes;

bool isPrime(int n) {
  bool result = true;
  if (primes.count(n)) {
    result = true;
  } else {
    for (int i = 2; i*i <= n; ++i) {
      if (n % i == 0) {
        result = false;
        break;
      }
    }
    if (result) {
      primes[n] = true;
    }
  }

  return result;
}

int rotate(int n) {
  int result = 0;
  int factor = 10;
  while (n >= 10) {
    result += (n % 10) * factor;
    n /= 10;
    factor *= 10;
  }
  result += n;

  return result;
}

bool isCircularPrime(int n) {
  bool result = true;
  int nOriginal = n;
  do {
    if (!isPrime(n)) {
      result = false;
      break;
    } else {
    }
    n = rotate(n);
  } while (n != nOriginal);

  return result;
}

int main() {
  int count = 0;
  for (int i = 2; i < 1000*1000; ++i) {
    if (isCircularPrime(i)) {
        count += 1;
    }
  }
  printf("There are %d circular primes below one million.\n", count);

  return 0;
}
