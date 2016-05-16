// Copyright 2016, Jens Hoffmann <xmcpam@gmail.com>
//
// Self powers
// Problem 48
//
// The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.
//
// Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
//

#include <stdio.h>


int main() {
    long result = 0;
    long modulo = 10000000000;
    for (int i = 1; i <= 1000; ++i) {
        long temp = i;
        for (int j = 1; j < i; ++j) {
            temp *= i;
            temp %= modulo;
        }
        result += temp;
        result %= modulo;
    }
    printf("Last ten digits of the series 1^1 + 1^2 + 3^3 + ... + 1000^1000: %ld\n", result);

    return 0;
}
