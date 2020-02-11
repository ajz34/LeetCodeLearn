//
// Created by ajz34 on 2020/2/11.
//

#ifndef E0008_STRING_TO_INTEGER_H
#define E0008_STRING_TO_INTEGER_H

#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        // 1. trim left
        int i = 0;
        for (i = 0; i < str.size(); ++i)
            if (str[i] != ' ') break;
        str = str.substr(i, str.size() - i);
        // 2. find first non-number character
        int sgn = 1; int sgn_char = 0;
        for (i = 0; i < str.size(); ++i) {
            if (i == 0 && (str[0] == '-' || str[0] == '+')) {
                sgn_char = 1;
                sgn = str[i] == '-' ? -1 : 1;
                continue; }
            if ('0' <= str[i] && str[i] <= '9') continue;
            break;
        }
        str = str.substr(sgn_char, i + 1 - sgn_char);
        // 3. trim left zeros
        for (i = 0; i < str.size(); ++i)
            if (str[i] != '0') break;
        str = str.substr(i, str.size() - i);
        // 4. exclude zero character
        if (str.empty()) return 0;
        // 5. exclude digit number > 12
        if (str.size() > 12) return sgn < 0 ? -2147483648 : 2147483647;
        // 6. first atol, then ltoi
        long l = atol(str.c_str()) * sgn;
        if (l > 2147483647) return 2147483647;
        else if (l < -2147483648) return -2147483648;
        else return int(l);
    }
};

#endif //TEST_CPP_E0008_STRING_TO_INTEGER_H
