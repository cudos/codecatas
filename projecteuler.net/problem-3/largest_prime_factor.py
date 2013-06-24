# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Problem 3 - Largest prime factor
#
# The prime factors of 13195 are 5, 7, 13 and 29.
#
# What is the largest prime factor of the number
# 600851475143 ?
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
import sys


def is_prime(number):
    for i in range(2, number / 2 + 1):
        if not (number % i):
            return False
    return True


def get_prime_factors(number):
    result = []
    while number > 1:
        i = 2
        while True:
            if not (number % i) and is_prime(i):
                result.append(i)
                number = number / i
                break
            i = i + 1
    return result


def get_largest_prime_factor(number):
    prime_factors = get_prime_factors(number)
    result = prime_factors[0]
    for factor in prime_factors[1:]:
        if factor > result:
            result = factor
    return result


def print_usage(program):
    print 'Usage: %s <number>' % program


def main():
    if len(sys.argv) <= 1:
        print_usage(sys.argv[0])
        sys.exit(0)
    number = int(sys.argv[1])
    result = get_largest_prime_factor(number)
    print 'The largest prime factor of %d is: %d' % (number, result)
    return 0


if __name__ == '__main__':
    sys.exit(main())
