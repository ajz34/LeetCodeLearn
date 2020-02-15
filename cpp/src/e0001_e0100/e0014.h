//
// Created by ajz34 on 2020/2/11.
//

#ifndef E0014_LONGEST_COMMON_PREFIX_H
#define E0014_LONGEST_COMMON_PREFIX_H

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int i = -1;
        while (true) {
            ++i;
            if (strs[0].size() <= i) break;
            char c = strs[0][i]; bool success = true;
            for (auto& str : strs)
                if (str.size() <= i || str[i] != c) {
                    success = false;
                    break;
                }
            if (!success) break;
        }
        return strs[0].substr(0, i);
    }
};

#endif //TEST_CPP_E0014_LONGEST_COMMON_PREFIX_H
