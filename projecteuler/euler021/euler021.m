#! /usr/bin/octave -qf
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Amicable numbers
# Problem 21
#
# Let d(n) be defined as the sum of proper divisors of n
# (numbers less than n which divide evenly into n).  If d(a)
# = b and d(b) = a, where a ≠ b, then a and b are an
# amicable pair and each of a and b are called amicable
# numbers.
#
# For example, the proper divisors of 220 are 1, 2, 4, 5,
# 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284.
# The proper divisors of 284 are 1, 2, 4, 71 and 142; so
# d(284) = 220.
#
# Evaluate the sum of all the amicable numbers under 10000.
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

function result = d(x)
    result = 0;
    for i = 1:x/2
        if (mod(x, i) == 0)
            result += i;
        endif
    endfor
end

result = 0;
visited = []

for a = 1:10000
    if (find(find(visited == 1) == a))
        continue;
    endif
    b = d(a);
    if (a != b && d(b) == a)
        printf("%i and %i are amicable numbers\n", a, b);
        result += a + b;
        visited(a) = 1;
        visited(b) = 1;
    endif
endfor

disp(result)
