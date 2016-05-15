// Copyright 2014, Jens Hoffmann
//
// Euler problem 45 - Triangular, pentagonal, and hexagonal
//
// Triangle, pentagonal, and hexagonal numbers are generated
// by the following formulae:
//
// Triangle        Tn=n(n+1)/2         1, 3, 6, 10, 15, ...
// Pentagonal      Pn=n(3n−1)/2        1, 5, 12, 22, 35, ...
// Hexagonal       Hn=n(2n−1)      1, 6, 15, 28, 45, ...
//
// It can be verified that T285 = P165 = H143 = 40755.
//
// Find the next triangle number that is also pentagonal and
// hexagonal.
//
#include <boost/multiprecision/cpp_int.hpp>


int main() {
    boost::multiprecision::cpp_int t = 0, p = 0, h = 1;
    boost::multiprecision::cpp_int tn = 0, pn= 0, hn = 1;
    int cnt = 0;

    while (cnt < 3) {
        while (p != h) {
            if (p < h) {
                pn += 1;
                p = pn * (3 * pn - 1) / 2;
            } else {
                hn += 1;
                h = hn * (2 * hn - 1);
            }
        }
        while (t < p) {
            tn += 1;
            t = tn * (tn + 1) / 2;
        }
        if (t == p) {
            std::cout << "T_" << tn << " = P_" << pn << " = H_" << hn << " = "
                << t << std::endl;
            cnt += 1;
        }
        pn += 1;
        p = pn * (3 * pn - 1) / 2;
    }

    return 0;
}

