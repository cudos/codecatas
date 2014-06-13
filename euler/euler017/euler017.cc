/**
 * Number letter counts - Euler problem 17
 *
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five,
 * then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 *
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out
 * in words, how many letters would be used?
 *
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and
 * forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20
 * letters. The use of "and" when writing out numbers is in compliance with
 * British usage.
 *
 *
 * Author: Jens Hoffmann <xmcpam@gmail.com>
 *
 **/
#include <stdio.h>

int main() {
    int *numbers = new int[1001];
    numbers[0] = 4;  // zero
    numbers[1] = 3;  // one
    numbers[2] = 3;  // two
    numbers[3] = 5;  // three
    numbers[4] = 4;  // four
    numbers[5] = 4;  // five
    numbers[6] = 3;  // six
    numbers[7] = 5;  // seven
    numbers[8] = 5;  // eight
    numbers[9] = 4;  // nine
    numbers[10] = 3;  // ten
    numbers[11] = 6;  // eleven
    numbers[12] = 6;  // twelve
    numbers[13] = 8;  // thirteen
    numbers[14] = 8;  // fourteen
    numbers[15] = 7;  // fifteen
    numbers[16] = 7;  // sixteen
    numbers[17] = 9;  // seventeen
    numbers[18] = 8;  // eighteen
    numbers[19] = 8;  // nineteen
    numbers[20] = 6;  // twenty
    numbers[30] = 6;  // thirty
    numbers[40] = 5;  // forty
    numbers[50] = 5;  // fifty
    numbers[60] = 5;  // sixty
    numbers[70] = 7;  // seventy
    numbers[80] = 6;  // eighty
    numbers[90] = 6;  // ninety
    numbers[1000] = 11;  // one thousand

    // Fill gaps in range 1..100
    for (int i = 2; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            numbers[i*10 + j] = numbers[i*10] + numbers[j];
        }
    }

    // Fill gaps in range 100..1000
    for (int i = 1; i < 10; i++) {
        numbers[i*100] = numbers[i] + 7;
        for (int j = 1; j < 100; j++) {
            numbers[i*100 + j] = numbers[i*100] + 3 + numbers[j];
        }
    }

    // Sum up result
    int result = 0;
    for (int i = 1; i <= 1000; i++) {
        result += numbers[i];
    }
    delete numbers;

    printf("Sum: %d\n", result);
    return 0;
}

