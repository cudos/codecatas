// Copyright 2014, Jens Hoffmann
//
// Euler problem 36 - Double-base palindromes
//
// The decimal number, 585 = 10010010012 (binary), is
// palindromic in both bases.
//
// Find the sum of all numbers, less than one million, which
// are palindromic in base 10 and base 2.
//
// (Please note that the palindromic number, in either base,
// may not include leading zeros.)
//
#include <stdio.h>


unsigned reverse(unsigned n) {
  unsigned result = 0;
  while (n > 0) {
    result = 10*result + n % 10;
    n = n / 10;
  }
  return result;
}

bool is_palindrom_base_10(unsigned n) {
  return n == reverse(n);
}

unsigned make_palindrom_base_2(unsigned n, bool odd) {
  unsigned result = n;
  if (odd) n = n >> 1;
  while (n > 0) {
    result = (result << 1) + (n & 1);
    n = n >> 1;
  }
  return result;
}

int main() {
  unsigned limit = 1000 * 1000;
  unsigned sum = 0;
  unsigned i, p;

  i = 1;
  p = make_palindrom_base_2(i, true);
  while (p < limit) {
    if (is_palindrom_base_10(p)) {
      sum += p;
    }
    i += 1;
    p = make_palindrom_base_2(i, true);
  }

  i = 1;
  p = make_palindrom_base_2(i, false);
  while (p < limit) {
    if (is_palindrom_base_10(p)) {
      sum += p;
    }
    i += 1;
    p = make_palindrom_base_2(i, false);
  }

  printf("The sum of all numbers palindromic below %d in base 10 and base 2"
      " is: %d\n", limit, sum);
  return 0;
}
