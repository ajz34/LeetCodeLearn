#include "extern.h"

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

TEST(e0100, e0013) {
    ASSERT_EQ(Solution().romanToInt("XXVII"), 27);
    ASSERT_EQ(Solution().romanToInt("MCMXCIV"), 1994);
}
