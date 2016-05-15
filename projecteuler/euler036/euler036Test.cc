// Copyright 2014, Jens Hoffmann
//
// euler036Test.cc
//
#include <stdio.h>
#include <cpptest.h>
#include "./euler036.h"
#include "./euler036Test.h"


void Euler36Test::test_is_palindrom() {
  std::vector<int> digits;

  digits = {0};
  TEST_ASSERT(is_palindrom(digits));

  digits = {2};
  TEST_ASSERT(is_palindrom(digits));

  digits = {1, 1};
  TEST_ASSERT(is_palindrom(digits));

  digits = {1, 0, 1};
  TEST_ASSERT(is_palindrom(digits));
}

void Euler36Test::test_is_decimal_palindrom() {
  int n;

  n = 2;
  TEST_ASSERT(is_decimal_palindrom(n));

  n = 101;
  TEST_ASSERT(is_decimal_palindrom(n));

  n = 200;
  TEST_ASSERT(!is_decimal_palindrom(n));
}

void Euler36Test::test_is_binary_palindrom() {
  int n = 2;
  TEST_ASSERT(!is_binary_palindrom(n));
}

void Euler36Test::test_shift_operation() {
  int n = 2;

  TEST_ASSERT((n & 1) == 0);

  n = n >> 1;
  TEST_ASSERT(n == 1);
}


int main() {
  Euler36Test tests;
  Test::TextOutput output(Test::TextOutput::Verbose);
  return tests.run(output);
}
