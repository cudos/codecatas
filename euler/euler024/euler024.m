#! /usr/bin/octave -qf
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# A permutation is an ordered arrangement of objects. For
# example, 3124 is one possible permutation of the digits 1,
# 2, 3 and 4. If all of the permutations are listed
# numerically or alphabetically, we call it lexicographic
# order. The lexicographic permutations of 0, 1 and 2 are:
# 
# 012   021   102   120   201   210
# 
# What is the millionth lexicographic permutation of the
# digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

format long;

n = 999999;
lehmer_code = [];
digits = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
permutation = [];


# Calculate Lehmer code
for i = fliplr(0:9)
    f = factorial(i);
    lehmer_code(end + 1) = floor(n / f);
    n = mod(n, f);
endfor

# Calculate permutation from Lehmer code
for l = lehmer_code
    permutation(end + 1) = digits(l + 1);
    digits(:, [l + 1]) = [];
endfor

# Calculate number from permutation
decimal_place = 0;
result = 0;
for p = fliplr(permutation)
    result += power(10, decimal_place) * p;
    decimal_place += 1;
endfor

disp(result);
