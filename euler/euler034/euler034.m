#! /usr/bin/octave -qf

n = 1

while (1)
    x = n;
    sum = 0;
    while (x)
        m = mod(x, 10);
        x -= m;
        x /= 10;
        sum += factorial(m);
    endwhile
    if (sum == n)
        disp(n)
    endif

    n += 1;
endwhile
