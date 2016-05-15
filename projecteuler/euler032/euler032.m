#! /usr/bin/octave -qf
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# We shall say that an n-digit number is pandigital if it
# makes use of all the digits 1 to n exactly once; for
# example, the 5-digit number, 15234, is 1 through 5
# pandigital.
#
# The product 7254 is unusual, as the identity, 39 × 186 =
# 7254, containing multiplicand, multiplier, and product is
# 1 through 9 pandigital.
#
# Find the sum of all products whose
# multiplicand/multiplier/product identity can be written as
# a 1 through 9 pandigital.

# HINT: Some products can be obtained in more than one way
# so be sure to only include it once in your sum.
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

function result = number_to_digits(n)
    result = [];

    while (n)
        m = mod(n, 10);
        result(end + 1) = m;
        n -= m;
        n /= 10;
    endwhile
end


sum = 0;
summands = [];


for r = [100, 1000; 999, 9999; 10, 1; 99, 9]
    for a = r(1):r(2)
        for b = r(3):r(4)
            c = a * b;
            ar = [];
            for x = [a, b, c]
                ar = [ar, number_to_digits(x)];
            endfor

            if (length(ar) != 9)
                continue;
            endif

            is_pandigital = 1;

            for i = 1:9
                if (!length(find(ar == i)) == 1)
                    is_pandigital = 0;
                    break;
                endif
            endfor

            if (is_pandigital)
                if (!length(find(summands == c)))
                    printf("%d %d %d\n", a, b, c);
                    summands = [summands, c];
                    sum += c;
                endif
            endif
        endfor
    endfor
endfor

disp(sum);


# while (i != 0)
#
#     disp(ar);
#     ar2 = ar;
#     # Generate permutations
#
#
#     # Generate combinations
#     i = k;
#     changed = 0;
#     while (!changed && i != 0)
#         if (ar(i) < n - k + i)
#             ar(i) += 1;
#             if (i < k)
#                 for j = i+1:k
#                     ar(j) = ar(j - 1) + 1;
#                 endfor
#             endif
#             changed = 1;
#         else
#             i -= 1;
#         endif
#     endwhile
# endwhile
