// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// A unit fraction contains 1 in the numerator. The decimal
// representation of the unit fractions with denominators 2
// to 10 are given:
//
//     1/2 =   0.5
//     1/3 =   0.(3)
//     1/4 =   0.25
//     1/5 =   0.2
//     1/6 =   0.1(6)
//     1/7 =   0.(142857)
//     1/8 =   0.125
//     1/9 =   0.(1)
//     1/10    =   0.1
//
// Where 0.1(6) means 0.166666..., and has a 1-digit
// recurring cycle. It can be seen that 1/7 has a 6-digit
// recurring cycle.
//
// Find the value of d < 1000 for which 1/d contains the
// longest recurring cycle in its decimal fraction part.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

typedef std::pair<size_t, size_t> NumberIndexPair;
typedef std::map<size_t, size_t> NumberIndexMap;

void print_map(const NumberIndexMap& m) {
    std::vector<std::pair<size_t, size_t>> v;
    std::copy(m.begin(), m.end(), std::back_inserter(v));
    std::sort(
        v.begin(), v.end(),
        [](const NumberIndexPair& a, const NumberIndexPair& b) -> bool {
            return a.second < b.second;
        }
    );

    for (const auto& x : v) {
        printf("(%d, %d)", x.first, x.second);
    }
    printf("\n");
}


int main() {
    NumberIndexMap rem;
    std::size_t r;
    std::size_t result = 0;
    std::size_t index;
    std::vector<std::size_t> cycle_length;

    // printf("Calculate recurring cycle lengths...\n");
    for (size_t d = 1; d < 10000; d++) {
        rem.clear();
        r = 1;
        index = 0;

        while (1) {

            r = r % d;

            if (r == 0 || rem.count(r)) {
                if (r == 0) {
                    result = 0;
                } else {
                    result = rem.size() - rem[r];
                }
                break;
            }

            rem[r] = index++;
            r *= 10;

            // printf(" * ");
            // print_map(rem);
        }
        // printf(" >>> 1/%d has cycle length: %d\n", d, result);
        cycle_length.push_back(result);
    }

    printf("Write results to file...\n");
    FILE* file = fopen("recurring-cycles.dat", "w");
    for (const auto& cl : cycle_length) {
        fprintf(file, "%d\n", cl);
    }
    fclose(file);

    return 0;
}
