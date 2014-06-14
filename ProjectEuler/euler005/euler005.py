# -*- coding: utf-8 -*-
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Problem 5 - Smallest multiple
#
# 2520 is the smallest number that can be divided by each of
# the numbers from 1 to 10 without any remainder.
#
# What is the smallest positive number that is evenly
# divisible by all of the numbers from 1 to 20?
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

number = 20

def is_divisible_by_all(x, divisors):
    for d in divisors:
        if x % d:
            return False
    return True


factors = range(1, number + 1)
factors_reduced = range(1, number + 1)
multiple = 1
for x in factors:
    multiple = multiple * x


for x in reversed(factors):
    if is_divisible_by_all(multiple / x, factors):
        factors_reduced.remove(x)
        multiple = multiple / x


print "Solution: %d" % multiple
print "Factors are: ", factors_reduced
