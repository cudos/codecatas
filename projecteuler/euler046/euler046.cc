// Copyright 2016, Jens Hoffmann <xmcpam@gmail.com>
//
// Goldbach's other conjecture
// Problem 46
//
// It was proposed by Christian Goldbach that every odd composite number can be
// written as the sum of a prime and twice a square.
//
// 9 = 7 + 2×1^2
// 15 = 7 + 2×2^2
// 21 = 3 + 2×3^2
// 25 = 7 + 2×3^2
// 27 = 19 + 2×2^2
// 33 = 31 + 2×1^2
//
// It turns out that the conjecture was false.
//
// What is the smallest odd composite that cannot be written as the sum of a
// prime and twice a square?

#include <stdio.h>


bool is_prime(int x) {
    if (x <= 1) return false;
    if (x <= 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (int i = 5; i*i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) return false;
    }
    return true;
}

bool is_sum_of_a_prime_and_twice_a_square(int x) {
    bool ret = false;
    int i = 1;
    int ts = 2;
    while (ts < x) {
        if (is_prime(x - ts)) {
            // printf("%d is sum of a prime and twice a square: %d + %d\n", x, x - ts, ts);
            ret = true;
            break;
        }
        ++i;
        ts = 2*i*i;
    }

    return ret;
}

int main() {
    int i = 3;

    while (1) {
        if (is_prime(i)) {
            i += 2;
            continue;
        }
        if (!is_sum_of_a_prime_and_twice_a_square(i)) {
            printf("%d cannot be written as a sum of a prime and twice a square\n", i);
            break;
        }
        i += 2;
    }

    return 0;
}
