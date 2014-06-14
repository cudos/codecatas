/**
 * Copyright 2014, Jens Hoffmann
 *
 * Problem 4 - Largest palindrome product
 *
 * A palindromic number reads the same both ways. The largest
 * palindrome made from the product of two 2-digit numbers is
 * 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two
 * 3-digit numbers.
 */

public class euler004 {
    public static boolean isPalindrome(int x) {
        int y = 0;
        int x2 = x;
        while (x2 != 0) {
            y *= 10;
            y += x2 % 10;
            x2 /= 10;
        }
        return x == y;
    }

    public static void main(String[] args) {
        int result = 0;
        for (int a = 999; a > 99; --a) {
            for (int b = a; b > 99; --b) {
                int product = a*b;
                if (product <= result) continue;
                if (isPalindrome(product)) {
                    result = product;
                }
            }
        }
        System.out.println(result);
    }
}
