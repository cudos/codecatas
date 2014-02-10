# -*- coding: utf-8 -*-
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Problem 7 - 10001st prime
#
# By listing the first six prime numbers: 2, 3, 5, 7, 11,
# and 13, we can see that the 6th prime is 13.
#
# Problem 7 - 10001st prime
# What is the 10 001st prime number?
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


def is_prime(x):
    for i in range(2, x / 2 + 1):
        if x % i == 0:
            return False
    return True


target_index = 10001
index = 2
number = 4
while True:
    if is_prime(number):
        index = index + 1

    if index == target_index:
        print 'Solution: %d' % number
        break

    number = number + 1
