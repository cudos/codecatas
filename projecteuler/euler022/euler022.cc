/**
 * Names scores - Euler Problem 22
 *
 * Using names.txt (right click and 'Save Link/Target As...'), a 46K text file
 * containing over five-thousand first names, begin by sorting it into
 * alphabetical order. Then working out the alphabetical value for each name,
 * multiply this value by its alphabetical position in the list to obtain a
 * name score.
 *
 * For example, when the list is sorted into alphabetical order, COLIN, which
 * is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN
 * would obtain a score of 938 × 53 = 49714.
 *
 * What is the total of all the name scores in the file?
 *
 * Author: Jens Hoffmann <xmcpam@gmail.com>
 **/
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>


void printVector(const std::vector<std::string>& vec) {
    for (auto e : vec) {
        std::cout << e << std::endl;
    }
}


int main() {
    std::ifstream inputFile;
    inputFile.open("names.txt");
    if (!inputFile.is_open()) {
        std::cout << "Error: Could not open file names.txt" << std::endl;
        exit(1);
    }

    char ch;
    bool start = false;
    std::vector<std::string> names;
    std::string name = "";
    while (!inputFile.eof()) {
        inputFile.get(ch);
        if (ch == '\"') {
            if (start == true) {
                names.push_back(name);
                name = "";
                start = false;
            } else {
                start = true;
            }
        }
        else if (ch == ',' || ch == ' ') {
            ;
        }
        else {
            name += ch;
        }
    }
    std::sort(names.begin(), names.end());
    // printVector(names);

    int score = 0;
    for (size_t i = 0; i < names.size(); i++) {
        int sum = 0;
        for (char ch : names[i]) {
            sum += ch - 64;
        }
        score += (i + 1) * sum;
    }

    printf("Score: %d\n", score);

    return 0;
}

