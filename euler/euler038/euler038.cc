// Copyright 2014, Jens Hoffmann
//
// Euler problem 38 - Pandigital multiplies
//
// Take the number 192 and multiply it by each of 1, 2, and 3:
//
//     192 × 1 = 192
//     192 × 2 = 384
//     192 × 3 = 576
//
// By concatenating each product we get the 1 to 9 pandigital, 192384576. We
// will call 192384576 the concatenated product of 192 and (1,2,3)
//
// The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4,
// and 5, giving the pandigital, 918273645, which is the concatenated product
// of 9 and (1,2,3,4,5).
//
// What is the largest 1 to 9 pandigital 9-digit number that can be formed as
// the concatenated product of an integer with (1,2, ... , n) where n > 1?
//
#include <stdio.h>
#include <algorithm>

int main() {
  int mmax = 0;
  int n = 1;

  while (1) {
    int m = 0;
    int i = 1;
    int d = 0;
    std::vector<int> map;
    while (n < 10000) {
      map.resize(10, 0);
      int x = n * i;
      int xr = 0;
      while (x) {
        xr *= 10;
        xr += x % 10;
        map[x % 10] = 1;
        x /= 10;
        d += 1;
      }
      if (d > 9) {
        break;
      }
      while (xr) {
        m *= 10;
        m += xr % 10;
        xr /= 10;
      }
      if (d == 9) {
        break;
      }
      i += 1;
    }
    if (i < 2) {
      break;
    }
    if (d != 9) {
      n += 1;
      continue;
    }
    if (std::find(map.begin()+1, map.end(), 0) != map.end()) {
      n += 1;
      continue;
    }
    if (m > mmax) {
      mmax = m;
    }
    n += 1;
  }
  printf("%d\n", mmax);
  return 0;
}

