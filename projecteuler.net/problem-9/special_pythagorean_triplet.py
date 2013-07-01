# -*- coding: utf-8 -*-
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Problem 9 - Special Pythagorean triplet
# 
# A Pythagorean triplet is a set of three natural numbers,
# a < b < c, for which, a^2 + b^2 = c^2
# 
# For example, 3^2 + 4^2 = 9 + 16 = 25 = 52.
# 
# There exists exactly one Pythagorean triplet for which
# a + b + c = 1000.  Find the product abc.
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
import math

a = 1
while a <= 1000:
    b = 1
    while b <= 1000:
        c_square = a*a + b*b
        c = math.sqrt(c_square)
        if c - int(c) == 0:
            # print 'Triple found: %d^2 + %d^2 = %d^2' % (a, b, c)
            if a + b + c == 1000:
                print 'Solution: a=%d, b=%d, c=%d, a*b*c=%d' % (a, b, c, a*b*c)
                break
        b = b + 1
    a = a + 1

