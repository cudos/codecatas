// Copyright 2016, Jens Hoffmann <xmcpam@gmail.com>
//
// Distinct primes factors
// Problem 47
//
// The first two consecutive numbers to have two distinct prime factors are:
//
// 14 = 2 × 7
// 15 = 3 × 5
//
// The first three consecutive numbers to have three distinct prime factors
// are:
//
// 644 = 2² × 7 × 23
// 645 = 3 × 5 × 43
// 646 = 2 × 17 × 19.
//
// Find the first four consecutive integers to have four distinct prime
// factors. What is the first of these numbers?

#include <stdio.h>

#define NUM_OF_PRIMES 130

int PRIMES[NUM_OF_PRIMES];

bool is_prime(int x) {
    if (x <= 1) return false;
    if (x <= 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (int i = 5; i*i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

bool has_num_of_distinct_prime_factors(int x, int num) {
    int cnt = 0;

    for (int i = 0; i < NUM_OF_PRIMES; ++i) {
        if (x == 1) break;
        int prime = PRIMES[i];
        if (x % prime == 0) {
            x /= prime;
            cnt += 1;
            if (cnt > num) return false;
            while (x % prime == 0) {
                x /= prime;
            }
        }
    }

    return cnt == num;
}

int main() {
    int i, cnt;
    int max = 4;

    // Precalculate the first NUM_OF_PRIMES primes
    cnt = 0;
    i = 2;
    while (cnt != NUM_OF_PRIMES) {
        if (is_prime(i)) {
            PRIMES[cnt] = i;
            cnt += 1;
        }
        i += 1;
    }

    i = 2;
    while (1) {
        if (has_num_of_distinct_prime_factors(i, max)) {
            bool found = true;
            for (int j = i + 1; j < i + max; ++j) {
                if (!has_num_of_distinct_prime_factors(j, max)) {
                    found = false;
                    break;
                }
            }
            if (found == true) {
                printf("The first of four consecutive numbers to have %d "
                    "distinct prime numbers: %d\n", max, i);
                break;
            }
        }
        ++i;
    }

    return 0;
}
