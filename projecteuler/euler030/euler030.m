#! /usr/bin/octave -qf

k = 1;
total = 0;


printf("Get range (k)...\n");
kmax = 1;

while (1)
    if (power(10, kmax - 1) > kmax * 59049)
        break;
    endif

    kmax += 1;
endwhile

kmax = kmax * 59049;
grenze = 0;

for x = power(10, kmax - 2):power(10, kmax - 1) - 1
    if (x > kmax)
        grenze = x;
        break;
    endif
endfor

for k = 1:kmax
    for an = power(10, k):power(10, k+1) - 1
        sum = 0;
        an2 = an;
        for n = 0:k
            x = mod(an2, 10);
            sum += x * (power(x, 4) - power(10, n));
            an2 -= x;
            an2 /= 10;
        endfor

        if (sum == 0)
            printf("Huray: %d\n", an);
            total += sum;
        endif
    endfor

    k += 1;
endfor

disp(total);
