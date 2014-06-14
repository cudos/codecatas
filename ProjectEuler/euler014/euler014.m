#!/usr/bin/octave -qf

MAX_STARTING_NUMBER = 1000000;
cs_length = 1;
cs_max_length = 0;
starting_number = 1;
n = starting_number;

CS_LENGTHS = [];
CS_LENGTHS(1) = 1;
CS_LENGTHS(2) = 2;

while (1)
    if (starting_number >= MAX_STARTING_NUMBER)
        break
    endif

    if (n <= length(CS_LENGTHS) && CS_LENGTHS(n))
        cs_length += CS_LENGTHS(n);
        n = 1;
    else
        if (mod(n, 2))
            n = 3 * n + 1;
        else
            n = n / 2;
        endif

        cs_length += 1;
    endif

    if (n == 1)
        CS_LENGTHS(starting_number) = cs_length;
        if (cs_length > cs_max_length)
            cs_max_length = cs_length;
            max_starting_number = starting_number;
        endif
        cs_length = 1;
        starting_number += 1;
        n = starting_number;
    endif
endwhile


printf(
    "The starting number %i produces a chain of length %i\n",
    max_starting_number, cs_max_length);
