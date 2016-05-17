// Copyright 2016, Jens Hoffmann <xmcpam@gmail.com>
//
// Prime permutations
// Problem 49
//
// The arithmetic sequence, 1487, 4817, 8147, in which each of the terms
// increases by 3330, is unusual in two ways: (i) each of the three terms are
// prime, and, (ii) each of the 4-digit numbers are permutations of one
// another.
//
// There are no arithmetic sequences made up of three 1-, 2-, or 3-digit
// primes, exhibiting this property, but there is one other 4-digit increasing
// sequence.
//
// What 12-digit number do you form by concatenating the three terms in this
// sequence?
//

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


int main() {
    // All primes from 1000 to 9999
    int primes[9000];
    int cnt = 0;
    for (int i = 1000; i <= 9999; ++i) {
        if (is_prime(i)) {
            printf("%d\n", i);
            primes[cnt] = i;
            cnt += 1;
        }
    }

    return 0;
}
