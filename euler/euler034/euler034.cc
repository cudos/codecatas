// Copyright 2014, Jens Hoffmann
//
// Euler problem 34 - Digit Factorials
//
// 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 =
// 145.
//
// Find the sum of all numbers which are equal to the sum of
// the factorial of their digits.
//
// Note: as 1! = 1 and 2! = 2 are not sums they are not
// included.
//


int main() {
  std::vector<int> factorials;
  factorials.push_back(1);
  int factorial = 1;
  for (int i = 1; i < 10; ++i) {
    factorial *= i;
    factorial.push_back(factorial);
  }

  std::vector<std::vector<int>> sums;

  int digits = 1;
  while (1) {
    for (int i = 0; i < digits; ++i) {
    }

    digits += 1;
  }
  return 0;
}

