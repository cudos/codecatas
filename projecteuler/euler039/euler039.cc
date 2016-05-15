// Copyright 2014, Jens Hoffmann
//
// Euler problem 39 - Integer right triangles
//
// If p is the perimeter of a right angle triangle with integral length sides,
// {a,b,c}, there are exactly three solutions for p = 120.
//
// {20,48,52}, {24,45,51}, {30,40,50}
//
// For which value of p ≤ 1000, is the number of solutions maximised?
//
#include <stdio.h>

int main() {
  int pmax = 0;
  int countmax = 0;
  int a, b, c;
  int nom, den;
  for (int p = 3; p <= 1000; ++p) {
    int count = 0;
    for (b = 1; b < p*(p - 2)/2/(p - 1); ++b) {
      nom = p*(p - 2*b);
      den = 2*(p - b);
      if (nom % den != 0) {
        continue;
      }
      a = nom / den;
      c = p - a - b;
      if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) {
        count += 1;
      }
    }
    if (count > countmax) {
      pmax = p;
      countmax = count;
    }
  }
  printf("For p = %d there are %d triple\n", pmax, countmax);
  return 0;
}
