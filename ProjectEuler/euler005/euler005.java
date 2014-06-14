/**
 * Copyright 2014, Jens Hoffmann
 *
 * Euler problem 5 - Smallest multiple
 *
 * 2520 is the smallest number that can be divided by each of
 * the numbers from 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly
 * divisible by all of the numbers from 1 to 20?
 */


public class euler005 {
    public static void main(String[] args) {
        long result = 1L;
        for (int i = 1; i <= 20; ++i) {
            result *= i;
        }
        for (int i = 20; i >= 1; --i) {
            boolean leaveFactor = true;
            for (int j = i; j <= 20; ++j) {
                if ((result / i) % j != 0) {
                    leaveFactor = false;
                    break;
                }
            }
            if (leaveFactor) {
                result /= i;
            }
        }
        System.out.println(result);
    }
}
