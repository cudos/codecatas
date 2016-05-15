// Copyright 2014, Jens Hoffmann
// Euler problem 29
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>


int main() {
  int max = 100;
  // double maxDelta = 1/100000000000000000.0;
  double maxDelta = 0.0; 

  double delta;
  int cnt = 0;
  for (int a1 = 2; a1 < max; ++a1) {
    for (int a2 = a1 + 1; a2 <= max; ++a2) {
      for (double b2 = 2; b2 < max; ++b2) {
        for (double b1 = b2 + 1; b1 <= max; ++b1) {
          // printf("a1: %d, b1: %d, a2: %d, b2: %d\n", a1, b1, a2, b2);
          delta = std::abs(log(a1) / log(a2) - b2 / b1);
          // printf("%f\n", delta);
          if (delta <= maxDelta) {
            printf("a1: %d, b1: %f, a2: %d, b2: %f\n", a1, b1, a2, b2);
            cnt += 1;
          }
        }
      }
    }
  }
  printf("%d\n", 99*99 - cnt);

  return 0;
}
