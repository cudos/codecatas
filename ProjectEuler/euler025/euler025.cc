// Copyright 2014, Jens Hoffmann
// 1000-digit Fibonacci number
// Euler problem 25
// 
#include <iostream>
#include "../utils.h"


int main() {
  LargeInt a(1), b(1), c(2), tmp;
  int term = 4;

  std::cout << LargeInt(8) + LargeInt(13) << std::endl;

  while (c.size() < 5) {
    std::cout << "c: " << c << ", size is: " << c.size() << std::endl;
    a = b;
    b = c;
    c = a + b;
    term += 1;
  }
  std::cout << "c: " << c << ", size is: " << c.size() << std::endl;
  printf("The first term in the Fibonacci sequence to contain 1000 digits is "
      "%d\n", term);

  return 0;
}
