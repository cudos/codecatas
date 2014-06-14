// Copyright 2014, Jens Hoffmann
//
// Euler problem 45 - Triangular, pentagonal, and hexagonal
//
// Triangle, pentagonal, and hexagonal numbers are generated
// by the following formulae:
//
// Triangle        Tn=n(n+1)/2         1, 3, 6, 10, 15, ...
// Pentagonal      Pn=n(3n−1)/2        1, 5, 12, 22, 35, ...
// Hexagonal       Hn=n(2n−1)      1, 6, 15, 28, 45, ...
//
// It can be verified that T285 = P165 = H143 = 40755.
//
// Find the next triangle number that is also pentagonal and
// hexagonal.
//
#include <stdio.h>
#include "../utils.h"

int main() {
  int a = 166;
  int r = 0;
  bool notFound = true;
  while (notFound) {
    int pa = (3*a*a - a) / 2;
    for (int b = a - 1; b > 0; --b) {
      int hb = 2*b*b - b;
      if (hb == pa && utils::isHexagonal(hb)) {
        notFound = false;
        r = b;
      }
    }
    ++a;
  }
  int result = 2*r*r - r;
  printf("%d at pindex: %d, hindex: %d\n", result, a - 1, r);
  return 0;
}
