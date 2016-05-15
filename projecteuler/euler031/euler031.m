#! /usr/bin/octave -qf


function result = euler31_helper(t, n)
    if (length(t) == 0)
        result = 0;
        return;
    endif

    if (length(t) == 1 && t == [1])
        result = 1;
        return;
    endif

    result = 0;

    for i = 0:n/t(end)
        result += euler31_helper(t(1:end-1), n - i*t(end));
    endfor
end

function result = euler31(t, n)
    result = 0;

    while (t(end) > n)
        t = t(1:end-1);
    endwhile

    printf("n = %d, t loos like:\n", n);
    disp(t);

    result = euler31_helper(t, n)
end

coins = [1, 2, 5, 10, 20, 50, 100, 200];
disp(euler31(coins, 200));
