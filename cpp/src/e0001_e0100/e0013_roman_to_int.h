//
// Created by ajz34 on 2020/2/11.
//

#ifndef E0013_ROMAN_TO_INT_H
#define E0013_ROMAN_TO_INT_H

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        vector<pair<int, string>> ROMAN {
                {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
                {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
                {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
                {1, "I"},
        };
        int r = 0; auto p = ROMAN.cbegin();
        while (!s.empty()) {
            if (s.substr(0, p->second.size()) == p->second) {
                r += p->first;
                s = s.substr(p->second.size());
            }
            else p = next(p);
        }
        return r;
    }
};

#endif //TEST_CPP_E0013_ROMAN_TO_INT_H
