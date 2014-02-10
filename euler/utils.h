// Copyright 2014, Jens Hoffmann
#ifndef UTILS_H
#define UTILS_H
#include <assert.h>
#include <vector>
#include <ostream>
#include <algorithm>


namespace utils {

template <typename T>
void swap(typename std::vector<T>* arr, size_t pos1, size_t pos2) {
  assert(pos1 < arr->size() && pos2 < arr->size());
  T tmp = (*arr)[pos1];
  (*arr)[pos1] = (*arr)[pos2];
  (*arr)[pos2] = tmp;
}

template <typename T>
bool nextPermutation(std::vector<T>* arr) {
  assert(arr->size() > 1);
  size_t i1, i2;
  // Find the rightmost element that is the first in a pair in ascending order
  for (i1 = arr->size() - 2, i2 = arr->size() - 1; (*arr)[i1] >= (*arr)[i2] && i1 != 0;
      i1--, i2--);
  if ((*arr)[i1] >= (*arr)[i2]) {
    std::reverse(arr->begin(), arr->end());
    return false;
  } else {
    // Find the rightmost elements to the right of i1 that is greater than
    // arr[i1]
    for (i2 = arr->size() - 1; i2 > i1 && (*arr)[i2] <= (*arr)[i1]; i2--);
    // Swap it with the first one
    utils::swap(arr, i1, i2);
    // Reverse the remainder
    std::reverse(arr->begin() + i1 + 1, arr->end());
  }
  return true;
}

template <typename T>
T concatenate(
    const typename std::vector<T>::const_iterator& begin,
    const typename std::vector<T>::const_iterator& end) {
  T result = 0;
  typename std::vector<T>::const_iterator it = begin;
  while (it != end) {
    T x = *it;
    if (x == 0) {
      result *= 10;
      it += 1;
      continue;
    }
    T xr = 0;
    while (x) {
      xr *= 10;
      xr += x % 10;
      x /= 10;
    }
    while (xr) {
      result *= 10;
      result += xr % 10;
      xr /= 10;
    }
    it += 1;
  }
  return result;
}


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
}  // namespace utils

#endif  // UTILS_H
