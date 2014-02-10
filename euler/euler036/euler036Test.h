// Copyright 2014, Jens Hoffmann
//
// euler036Test.h
//
#ifndef EULER0_36_TEST
#define EULER0_36_TEST

#include <cpptest.h>

class Euler36Test : public Test::Suite {
  public:
  Euler36Test() {
    TEST_ADD(Euler36Test::test_shift_operation);
    TEST_ADD(Euler36Test::test_is_palindrom);
    TEST_ADD(Euler36Test::test_is_decimal_palindrom);
    TEST_ADD(Euler36Test::test_is_binary_palindrom);
  }

  private:
  void test_shift_operation();
  void test_is_palindrom();
  void test_is_decimal_palindrom();
  void test_is_binary_palindrom();
};

#endif  // EULER0_36_TEST
