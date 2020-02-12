//
// Created by ajz34 on 2020/2/12.
//

#ifndef E0017_LETTER_COMB_H
#define E0017_LETTER_COMB_H

#include <vector>
#include <string>
using namespace std;

class Solution {
    vector<string> LETTER { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

public:
    vector<string> letterInter(string& digits, const vector<string>& strs) {
        if (digits.empty()) return strs;
        vector<string> result {};
        int digit = digits.back() - '0'; digits.pop_back();
        for (char l : LETTER[digit])
            for (const string& str : strs)
                result.push_back(l + str);
        return letterInter(digits, result);
    }

    vector<string> letterCombinations(string& digits) {
        vector<string> result { "" };
        result = letterInter(digits, result);
        return result.size() == 1 ? vector<string>{} : result;  // exclude no digit situation
    }
};

#endif //TEST_CPP_E0017_LETTER_COMB_H
