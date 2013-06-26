# -*- coding: utf-8 -*-
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Problem 4 - Largest palindrome product
# 
# A palindromic number reads the same both ways. The largest
# palindrome made from the product of two 2-digit numbers is
# 9009 = 91 × 99.
# 
# Find the largest palindrome made from the product of two
# 3-digit numbers.
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
import sys


def is_palindrome(number):
    number_as_str = str(number)
    number_len = len(number_as_str)
    for i in range(0, number_len / 2 + 1):
        if number_as_str[i] != number_as_str[number_len - i - 1]:
            return False
    return True
 

def main():
    min_number = 100 * 100
    max_number = 999 * 999
    for i in range(max_number, min_number - 1, -1):
        if is_palindrome(i):
            for j in range(100, 1000):
                if i % j == 0:
                    k = i / j
                    if len(str(j)) == 3 and len(str(k)) == 3:
                        print 'Palindrome: %d; Divisor 1: %d; Divisor 2: %d' % (i, j, i / j)
                        return 0
    return 0


if __name__ == '__main__':
    sys.exit(main())
