// Copyright 2014, Jens Hoffmann
// Euler problem 20
// Find the sum of the digits in the number 100!
#include "../utils.h"


int main() {
  LargeInt x(1);

  for (int i = 1; i <= 100; ++i) {
    x = x * LargeInt(i);
  }
  printf("%d\n", x.crossSum());

  return 0;
}
