/**
 * Copyright 2014, Jens Hoffmann
 *
 * Euler problem 9 - Special Pythagorean triplet
 *
 * A Pythagorean triplet is a set of three natural numbers,
 * a < b < c, for which, a^2 + b^2 = c^2
 *
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5**2.
 *
 * There exists exactly one Pythagorean triplet for which
 * a + b + c = 1000.  Find the product abc.
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */


public class euler009 {
    public static void main(String[] args) {
        for (int c = 998; c > ,w
        for (int a = 1; a <= 1000; ++a) {
            for (int b = a + 1; b <= 1000; ++b) {
                if (a + b >= 1000) break;
                int c = 1000 - a - b;
                if (a*a + b*b == c*c) {
                    System.out.println(a*b*c);
                    return;
                }
            }
        }
    }
}