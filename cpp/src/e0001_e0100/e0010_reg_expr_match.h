//
// Created by ajz34 on 2020/2/11.
//

#ifndef E0010_REG_EXPR_MATCH_H
#define E0010_REG_EXPR_MATCH_H

#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // TODO: Low Efficiency
        // recursive: success condition
        if (p.empty()) return s.empty();
        if (p.size() == 1) return (s.size() == 1 && (p[0] == '.' || s[0] == p[0]));
        // assert p.size() >= 2, second char != or == '*'
        if (p[1] != '*')
            return !s.empty() && (p[0] == '.' || s[0] == p[0]) && isMatch(s.substr(1), p.substr(1));
        else {
            // zero char same
            if (isMatch(s, p.substr(2))) return true;
            // one or more char same
            while (p[0] == '.' || s[0] == p[0]) {
                if (s.empty()) return false;
                s = s.substr(1);
                if (isMatch(s, p.substr(2))) return true;
            }
        }
        return false;  // should not exec this line, only suppress ide warning
    }
};

#endif //TEST_CPP_E0010_REG_EXPR_MATCH_H
