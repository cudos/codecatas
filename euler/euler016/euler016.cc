// Copyright 2014, Jens Hoffmann
#include <iostream>
#include <vector>
#include <algorithm>
#include "../utils.h"


int main() {
  LargeInt x(1);

  for (size_t i = 0; i < 1000; ++i) {
    x = x + x;
  }
  std::cout << x.getCrossSum() << std::endl;

  return 0;
}
