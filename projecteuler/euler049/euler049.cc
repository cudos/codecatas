// Copyright 2016, Jens Hoffmann <xmcpam@gmail.com>
//
// Prime permutations
// Problem 49
//
// The arithmetic sequence, 1487, 4817, 8147, in which each of the terms
// increases by 3330, is unusual in two ways: (i) each of the three terms are
// prime, and, (ii) each of the 4-digit numbers are permutations of one
// another.
//
// There are no arithmetic sequences made up of three 1-, 2-, or 3-digit
// primes, exhibiting this property, but there is one other 4-digit increasing
// sequence.
//
// What 12-digit number do you form by concatenating the three terms in this
// sequence?
//

#include <vector>
#include <iostream>
#include <algorithm>


void print_vector(const std::vector<int>& v) {
    for (auto x: v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}


bool is_prime(int x) {
    if (x <= 1) return false;
    if (x <= 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (int i = 5; i*i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) return false;
    }
    return true;
}


void get_permutations(int x, std::vector<int>* result) {
    // std::cout << "Permutations of " << x << std::endl;
    std::vector<int> digits;
    int mod;
    while (1) {
        if (x == 0) break;
        mod = x % 10;
        digits.push_back(mod);
        x /= 10;
    }
    std::sort(digits.begin(), digits.end());

    do {
        int v = 0;
        for (int i : digits) {
            v *= 10;
            v += i;
        }
        if (v < 1000) continue;
        if (is_prime(v)) {
            result->push_back(v);
        }
        // std::cout << "  " << v << std::endl;
    } while (std::next_permutation(digits.begin(), digits.end()));
}


void find_three_equidistant_elements(
        const std::vector<int>& numbers,
        std::vector<std::vector<int> > *result
) {
    for (size_t i = 0; i < numbers.size() - 2; ++i) {
        int dist_1 = 0;
        int dist_2 = 0;
        for (size_t j = i + 1; j < numbers.size() - 1; ++j) {
            dist_1 = numbers[j] - numbers[i];
            for (size_t k = j + 1; k < numbers.size(); ++k) {
                dist_2 = numbers[k] - numbers[j];
                if (dist_1 == dist_2) {
                    std::vector<int> hit {numbers[i], numbers[j], numbers[k]};
                    result->push_back(hit);
                }
            }
        }
    }
}


int main() {
    int primes[9000];
    int cnt = 0;
    int seq_length = 3;
    std::vector<std::vector<int> > result;

    for (int i = 1000; i <= 9999; ++i) {
        std::vector<int> permutations;
        get_permutations(i, &permutations);
        if (permutations.size() < seq_length) {
            continue;
        }
        find_three_equidistant_elements(permutations, &result);
    }
    if (result.size() != 0) {
        for (auto x: result) {
            print_vector(x);
        }
    }

    return 0;
}
