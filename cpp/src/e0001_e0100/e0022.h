//
// Created by ajz34 on 2020/2/15.
//

#ifndef E0022_GENERATE_PARENTHESES_H
#define E0022_GENERATE_PARENTHESES_H

#include <set>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    set<int> insert_binary_10(int s) {
        set<int> result{};
        int bit = 1;
        while (bit < s) {
            bit *= 2;
        }
    }
    vector<string> generateParenthesis(int n) {
        return {};
    }
};

#endif //TEST_CPP_E0022_GENERATE_PARENTHESES_H
