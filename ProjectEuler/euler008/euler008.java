/**
 * Copyright 2014, Jens Hoffmann
 *
 * Euler problem 8 - Largest product in a series
 *
 * Find the greatest product of five consecutive digits in
 * the 1000-digit number (number.txt).
 */
import java.io.FileReader;
import java.io.IOException;


public class euler008 {
    public static void main(String[] args) throws IOException {
        FileReader inputStream = null;
        int[] fiveNumbers = new int[5];
        int result = 0;
        try {
            inputStream = new FileReader("number.txt");
            int c;
            while ((c = inputStream.read()) != -1) {
                if (c == '\n') continue;
                fiveNumbers[0] = fiveNumbers[1];
                fiveNumbers[1] = fiveNumbers[2];
                fiveNumbers[2] = fiveNumbers[3];
                fiveNumbers[3] = fiveNumbers[4];
                fiveNumbers[4] = c - 48;
                int product = 1;
                for (int i = 0; i < 5; i++) {
                    product *= fiveNumbers[i];
                }
                if (product > result) {
                    result = product;
                }
            }
        } finally {
            if (inputStream != null) {
                inputStream.close();
            }
        }
        System.out.println(result);
    }
}
