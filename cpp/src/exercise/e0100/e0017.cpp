#include "extern.h"

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

TEST(e0100, e0017) {
    string s1 = "23";
    vector<string> r1{ "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" };
    ASSERT_THAT(Solution().letterCombinations(s1), r1);
}
