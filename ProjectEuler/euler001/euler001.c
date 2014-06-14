// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Multiples of 3 and 5
// Problem 1
//
// If we list all the natural numbers below 10 that are
// multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of
// these multiples is 23.
//
// Find the sum of all the multiples of 3 or 5 below 1000.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <stdio.h>
#include <stdlib.h>


void printUsage(char* progname) {
    printf("Find the sum of all the multiples of 3 or 5 below <number>\n"
           "Usage: %s <number>\n", progname);
}


int main(int argc, char** argv) {
    if (argc == 1) {
        printUsage(argv[0]);
        exit(0);
    }

    int n = atoi(argv[1]) - 1;
    int result = 3 * (n / 3) * (n / 3 + 1) / 2;
    result += 5 * (n / 5) * (n / 5 + 1) / 2;
    result -= 15 * (n / 15) * (n / 15 + 1) / 2;
    printf(
        "The sum of all the multiples of 3 or 5 below %d is: %d\n",
        n + 1, result
    );
}
