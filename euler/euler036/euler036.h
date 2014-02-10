// Copyright 2014, Jens Hoffmann
//
#include <vector>


bool is_palindrom(const std::vector<int>& digits) {
  bool result = true;
  for (size_t i = 0; i < digits.size() / 2; ++i) {
    if (digits[i] != digits[digits.size() - i - 1]) {
      result = false;
      break;
    }
  }

  return result;
}

bool is_binary_palindrom(int n) {
  std::vector<int> digits;
  int i = 0;
  while (n) {
    digits.push_back(n & 1);
    n = n >> 1;
    ++i;
  }

  return is_palindrom(digits);
}

bool is_decimal_palindrom(int n) {
  std::vector<int> digits;
  while (n) {
    digits.push_back(n % 10);
    n = n / 10;
  }

  return is_palindrom(digits);
}
