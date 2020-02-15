//
// Created by ajz34 on 2020/2/12.
//

#ifndef E0020_VALID_PARENTHESE_H
#define E0020_VALID_PARENTHESE_H

#include <string>
#include <stack>
#include <assert.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk{};
        for (char& c : s) {
            switch (c) {
                case '(': stk.push('('); break;
                case ')': if (stk.empty() || stk.top() != '(') return false; else stk.pop(); break;
                case '[': stk.push('['); break;
                case ']': if (stk.empty() || stk.top() != '[') return false; else stk.pop(); break;
                case '{': stk.push('{'); break;
                case '}': if (stk.empty() || stk.top() != '{') return false; else stk.pop(); break;
                default: assert(false);
            }
        }
        return stk.empty();
    }
};

#endif //TEST_CPP_E0020_VALID_PARENTHESE_H
