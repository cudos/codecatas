#! /usr/bin/octave -qf
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Author: Jens Hoffmann
#
# Calculate and plot the number of divisors of
# triangle numbers
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

TNR = [1];  # triangle numbers
DIV = [1];  # divisors

n = 2;      # position of triangle number
tnr = 3;    # triangle number

while (1)
    # Calculate the number of divisors of triangle number tnr
    factors = factor(tnr);
    [a, b, c] = unique(factors);
    b = histc(c, 1:length(b));
    nofDivisors = 1;
    for i = b
        nofDivisors *= i + 1;
    endfor

    # Store triangle number and it's number of divisors
    TNR(end + 1) = tnr;
    DIV(end + 1) = nofDivisors;

    # Stop condition
    if (nofDivisors > 10000)
        printf("Triangle number with %i divisors: %i\n", nofDivisors, tnr);
        break;
    endif
 
    # Calculate next triangle number
    n += 1;
    tnr += n;
endwhile

plot(TNR, DIV);
print("num_of_divisors_over_triangle_numbers.png");

