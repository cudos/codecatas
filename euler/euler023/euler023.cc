// Copyright 2014, Jens Hoffmann
//
// Euler problem 23 - Non-abundant sums
//
// A perfect number is a number for which the sum of its proper
// divisors is exactly equal to the number. For example, the
// sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14
// = 28, which means that 28 is a perfect number.
//
// A number n is called deficient if the sum of its proper
// divisors is less than n and it is called abundant if this
// sum exceeds n.
//
// As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 =
// 16, the smallest number that can be written as the sum of
// two abundant numbers is 24. By mathematical analysis, it can
// be shown that all integers greater than 28123 can be written
// as the sum of two abundant numbers. However, this upper
// limit cannot be reduced any further by analysis even though
// it is known that the greatest number that cannot be
// expressed as the sum of two abundant numbers is less than
// this limit.
//
// Find the sum of all the positive integers which cannot be
// written as the sum of two abundant numbers.
#include <vector>
#include <stdio.h>


std::vector<int> abundant_numbers;

bool is_abundant(int n) {
  int result = 1;
  for (int i = 2; i*i <= n; ++i) {
    if (n % i == 0) {
      result += i;
      if (i * i != n)
        result += n / i;
    }
  }
  return result > n;
}

int main() {
  int limit = 28123;

  for (int i = 12; i <= limit; ++i) {
    if (is_abundant(i)) {
      abundant_numbers.push_back(i);
    }
  }

  std::vector<int> sum_of_two_abundant_numbers(limit + 1, 0);
  unsigned sum;
  for (std::size_t i = 0; i < abundant_numbers.size(); i++) {
    for (std::size_t j = i; j < abundant_numbers.size(); j++) {
      sum = abundant_numbers[i] + abundant_numbers[j];
      if (sum < sum_of_two_abundant_numbers.size()) {
        sum_of_two_abundant_numbers[sum] = 1;
      }
    }
  }

  sum = 0;
  for (std::size_t i = 0; i < sum_of_two_abundant_numbers.size(); ++i) {
    if (sum_of_two_abundant_numbers[i] == 0) {
      sum += i;
    }
  }

  printf("The sum of all numbers that can't be expressed as sum of two abundant"
      "numbers is %d\n", sum);

  return 0;
}
