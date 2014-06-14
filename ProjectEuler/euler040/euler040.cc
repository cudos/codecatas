// Copyright 2014, Jens Hoffmann
//
// Euler problem 40 - Champernowne's constant
//
// An irrational decimal fraction is created by concatenating the positive
// integers:
//
// 0.123456789101112131415161718192021...
//
// It can be seen that the 12th digit of the fractional part is 1.
//
// If dn represents the nth digit of the fractional part, find the value of the
// following expression.
//
// d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
//
#include <stdio.h>

int main() {
  int result = 1;
  int x = 1;
  int index = 1;
  int t = 1;
  int xr, d, y, cnt;
  while (t <= 1000*1000) {
    y = x;
    xr = 0;
    cnt = 0;
    while (y) {
      xr *= 10;
      xr += y % 10;
      y /= 10;
      cnt += 1;
    }
    while (cnt) {
      d = xr % 10;
      xr /= 10;
      if (index == t) {
        result *= d;
        t *= 10;
      }
      index += 1;
      cnt -= 1;
    }
    x += 1;
  }
  printf("%d\n", result);
  return 0;
}
