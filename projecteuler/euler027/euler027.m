#! /usr/bin/octave -qf
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Euler discovered the remarkable quadratic formula:
#
# n² + n + 41
#
# It turns out that the formula will produce 40 primes for
# the consecutive values n = 0 to 39. However, when n = 40,
# 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and
# certainly when n = 41, 41² + 41 + 41 is clearly divisible
# by 41.
#
# The incredible formula  n² − 79n + 1601 was discovered,
# which produces 80 primes for the consecutive values n = 0
# to 79. The product of the coefficients, −79 and 1601, is
# −126479.
#
# Considering quadratics of the form:
#
#     n² + an + b, where |a| < 1000 and |b| < 1000
#
#     where |n| is the modulus/absolute value of n
#     e.g. |11| = 11 and |−4| = 4
#
# Find the product of the coefficients, a and b, for the
# quadratic expression that produces the maximum number of
# primes for consecutive values of n, starting with n = 0.
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# RANGE = [0:-1:-999];
RANGE = [0:999 0:-1:-999];
global NUMS = [];

function result = get_num_of_primes(a, b)
    global NUMS;
    n = 0;
    result = 0;

    while (1)
        p = n * n + a * n + b;

        if (p > 0)
            # printf("FFFO");
            if (length(NUMS) < p)
                NUMS(p) = 0;
            endif

            np = NUMS(p);
            if (np == 2)
                result += 1;
            elseif (np == 1)
                break;
            else
                if (factor(p) == p)
                    NUMS(p) = 2;
                    result += 1;
                else
                    NUMS(p) = 1;
                    break;
                endif
            endif
        else
            break;
        endif

        n += 1;
    endwhile
end

max_nof_primes = 0;
product = 0;

for a = RANGE
    # printf(".");
    nof_primes = 0;
    for b = RANGE
        nof_primes = get_num_of_primes(a, b);
        if (nof_primes > max_nof_primes)
            printf("a = %d, b = %d: %d primes\n", a, b, nof_primes);
            max_nof_primes = nof_primes;
            product = a * b;
        endif
    endfor
endfor

printf("n^2 + a*n + b with a = %d, b = %d produces %d consecutive primes\n",
    a, b, max_nof_primes);
printf("a * b = %d", a * b);
