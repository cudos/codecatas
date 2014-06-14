/**
 * Copyright 2014, Jens Hoffmann
 *
 * Euler problem 3 - Largest prime factor
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number
 * 600851475143 ?
 */


public class euler003 {
    public static boolean isPrime(long x) {
        if (x == 0 || x == 1) return false;
        if (x % 2 == 0 || x % 3 == 0) return false;
        for (int i = 5; i*i < x; i += 6) {
            if (x % i == 0 || x % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        long number = 600851475143L;
        long result = 0L;
        for (long x = (long) Math.sqrt(number); x > 0; --x) {
          if (number % x == 0 && isPrime(x)) {
            result = x;
            break;
          }
        }
        System.out.println(result);
    }
}
