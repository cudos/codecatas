#! /usr/bin/octave -qf


for a1 = 1:9
    for a2 = 1:9
        a = a1 * 10 + a2;
        for b1 = 1:9
            for b2 = 1:9
                b = b1*10 + b2;
                x = a / b;
                if (x >= 1)
                    continue
                elseif(a2 == 0 && b2 == 0)
                    continue
                elseif ((a1 == b1 && x == a2/b2) || (a1 == b2 && x == a2/b1) || (a2 == b1 && x == a1/b2) || (a2 == b2 && x == a1/b1))
                    printf("%d/%d\n", a, b);
                endif
            endfor
        endfor
    endfor
endfor
