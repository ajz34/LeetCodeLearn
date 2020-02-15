//
// Created by ajz34 on 2020/2/10.
//

#ifndef E0005_PALINDROMIC_SUBSTRING_H
#define E0005_PALINDROMIC_SUBSTRING_H

#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int l, r, len;
        int l_max = 0, r_max = 0, len_max = 0;
        for (int i = 0; i <= 2 * (s.size() - 1); ++i) {
            if (i % 2 == 0) l = r = i / 2;
            else { l = (i - 1) / 2; r = (i + 1) / 2; }
            while (l >= 0 && r < s.size()) {
                if (s[l] != s[r]) break;
                len = r - l + 1;
                if (len > len_max) { l_max = l; r_max = r; len_max = len; }
                --l; ++r;
            }
        }
        return s.substr(l_max, len_max);
    }
};

#endif //TEST_CPP_E0005_PALINDROMIC_SUBSTRING_H
