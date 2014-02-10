#! /usr/bin/octave -qf
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# A unit fraction contains 1 in the numerator. The decimal
# representation of the unit fractions with denominators 2
# to 10 are given:
#
#     1/2 =   0.5
#     1/3 =   0.(3)
#     1/4 =   0.25
#     1/5 =   0.2
#     1/6 =   0.1(6)
#     1/7 =   0.(142857)
#     1/8 =   0.125
#     1/9 =   0.(1)
#     1/10    =   0.1
#
# Where 0.1(6) means 0.166666..., and has a 1-digit
# recurring cycle. It can be seen that 1/7 has a 6-digit
# recurring cycle.
#
# Find the value of d < 1000 for which 1/d contains the
# longest recurring cycle in its decimal fraction part.
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

format long;

function result = get_recurring_cycle_length(x, y)
    rem = [];
    result = 0;

    if (y > x)
        x *= 10;
    endif

    while (y > x)
        rem(end + 1) = x;
        x *= 10;
    endwhile

    while (1)
        if (x == 0)
            result = 0;
            break;
        endif

        if (y > x)
            x *= 10;
        else
            rem(end + 1) = x;
            x = mod(x, y);
        endif

        index = find(rem == x);
        if (index)
            result = length(rem) - index + 1;
            break;
        endif
    endwhile
end

max_cycle_length = 0;
max_d = 0;
CYCLES_X = [];
CYCLES_Y = [];

for d = 0:1000
    cl = get_recurring_cycle_length(1, d);
    CYCLES_X(end + 1) = d;
    CYCLES_Y(end + 1) = cl;
    if (cl > max_cycle_length)
        max_cycle_length = cl;
        max_d = d;
    endif
endfor

printf("1/%i has a recurring cycle length of %i\n", max_d, max_cycle_length);

PRIMES_X = [];
PRIMES_Y = [];

for d = CYCLES_X
    if (factor(d) == d)
        PRIMES_X(end + 1) = d;
        PRIMES_Y(end + 1) = CYCLES_Y(find(CYCLES_X == d));
    endif
endfor

plot(CYCLES_X, CYCLES_Y, "+g", PRIMES_X, PRIMES_Y, "^b");
print("foo.png");

# get_recurring_cycle_length(1, 13)
# get_recurring_cycle_length(1, 7)
# get_recurring_cycle_length(1, 6)
# get_recurring_cycle_length(1, 3)
# get_recurring_cycle_length(10, 3)
# get_recurring_cycle_length(10, 3)
# get_recurring_cycle_length(100, 7)
