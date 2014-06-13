/**
 * Copyright 2014, Jens Hoffmann
 *
 * Euler problem 7 - 10001st prime
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11,
 * and 13, we can see that the 6th prime is 13.
 *
 * What is the 10001st prime number?
 */

public class euler007 {
    public static boolean isPrime(int x) {
        if (x < 2) return false;
        if (x == 2 || x == 3) return true;
        if (x % 2 == 0 || x % 3 == 0) return false;
        for (int i = 5; i*i <= x; i += 6) {
            if (x % i == 0 || x % (i + 2) == 0) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        int result = 0;
        int primeIndex = 0;
        int i = 2;
        while (primeIndex != 10001) {
            if (isPrime(i)) {
                result = i;
                primeIndex++;
            }
            i++;
        }
        System.out.println(result);
    }
}
