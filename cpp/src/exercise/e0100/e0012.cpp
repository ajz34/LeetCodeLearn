//
// Created by ajz34 on 2020/2/11.
//

#include "extern.h"

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> ROMAN {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
            {1, "I"},
        };
        string s; auto p = ROMAN.cbegin();
        s.reserve(40);
        while (num > 0) {
            if (p->first > num) p = next(p);
            else {
                num -= p->first;
                s += p->second;
            }
        }
        return s;
    }
};

TEST(e0100, e0012) {
    ASSERT_EQ(Solution().intToRoman(27), "XXVII");
    ASSERT_EQ(Solution().intToRoman(1994), "MCMXCIV");
}
