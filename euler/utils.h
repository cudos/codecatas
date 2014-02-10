// Copyright 2014, Jens Hoffmann
#ifndef UTILS_H
#define UTILS_H
#include <vector>
#include <ostream>


class LargeInt {
  public:
  LargeInt() { }
  explicit LargeInt(int x) {
    int mod;
    while (x) {
      mod = x % 10;
      _number.push_back(mod);
      x -= mod;
      x /= 10;
    }
  }

  LargeInt& operator=(const LargeInt& other) {
    if (this != &other) {
      _number = other._number;
    }
    return *this;
  }

  LargeInt operator+(const LargeInt& other) {
    const LargeInt *a, *b;
    LargeInt result;

    if (_number.size() > other._number.size()) {
      a = this;
      b = &other;
    } else {
      a = &other;
      b = this;
    }

    result._number.resize(a->_number.size() + 1);
    int carry = 0, tmp;
    size_t i = 0, j = 0;
    while (i < a->_number.size() || j < b->_number.size()) {
      tmp = a->_number[i] + b->_number[j] + carry;
      result._number[i] = tmp % 10;
      carry = tmp / 10;
      i += 1;
      j += 1;
    }
    if (carry) {
      result._number.back() = carry;
    } else {
      result._number.resize(result._number.size() - 1);
    }

    return result;
  }

  LargeInt operator*(const LargeInt& other) {
    LargeInt result;
    return result;
  }

  friend std::ostream& operator<<(std::ostream& out, const LargeInt& x) {
    std::vector<int>::const_iterator it;
    for (it = x._number.end() - 1; it >= x._number.begin(); --it) {
      out << *it;
    }
    return out;
  }

  int getCrossSum() {
    int result = 0;
    for (size_t i = 0; i < _number.size(); ++i) {
      result += _number[i];
    }
    return result;
  }

  size_t size() {
    return _number.size();
  }

  private:
  std::vector<int> _number;
};

#endif  // UTILS_H
