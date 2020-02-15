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
        while (bit <= s) {
            // example: 101100, bit = 2^3, then insert 10 into the third number, i.e. 1011(10)00 => 10111000
            result.insert(s % bit + s / bit * 4 * bit + 2 * bit);
            bit *= 2;
        }
        return result;
    }

    string binary_to_str(int i) {
        string s = "";
        while (i > 0) {
            s += i % 2 == 1 ? ')' : '(';
            i /= 2;
        }
        return s;
    }

    vector<string> generateParenthesis(int n) {
        if (n == 0) return {};
        set<int> binary_set{ 2 };
        for (int i = 2; i <= n; ++i) {
            set<int> current_set{};
            for (int val : binary_set) {
                auto s = this->insert_binary_10(val);
                current_set.insert(s.begin(), s.end());
            }
            binary_set = current_set;
        }
        vector<string> result{};
        for (int val : binary_set)
            result.push_back(this->binary_to_str(val));
        return result;
    }
};

#endif //TEST_CPP_E0022_GENERATE_PARENTHESES_H
