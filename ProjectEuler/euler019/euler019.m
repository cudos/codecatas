#! /usr/bin/octave -qf

day_name = 1;
day = 1;
month = 1;
year = 1900;
sunday_count = 0;

while (day != 31 || month != 12 || year != 2000)

    # Sunday occurs on the first of a month
    if (year >= 1901 && day == 1 && day_name == 7)
        sunday_count += 1;
    endif

    # Year ends
    if (day == 31 && month == 12)
        day = 1;
        month = 1;
        year += 1;

    # February ends
    elseif (month == 2 && day >= 28)
        # February has 29 days in leap years
        if (mod(year, 4) == 0 && (mod(year, 100) != 0 || mod(year, 400) == 0))
            if (day == 28)
                day += 1;
            else
                day = 1;
                month = 3;
            endif
        # February has 28 days in non leap years
        else
            day = 1;
            month = 3;
        endif

    # Month with 30 days ends
    elseif (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11))
        day = 1;
        month += 1;

    # Month with 31 days ends (not December)
    elseif (day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 ||
                           month == 8 || month == 10))
        day = 1;
        month += 1;

    # A normal day ends
    else
        day += 1;
    endif

    day_name += 1;
    if (day_name == 8)
        day_name = 1;
    endif
endwhile

disp(sunday_count)
