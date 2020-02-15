//
// Created by ajz34 on 2020/2/12.
//

#include "pch.h"
#include "../../src/e0001_e0100/e0017.h"

TEST(e0001_e0100, e0017) {
    string s1 = "23";
    vector<string> r1 { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" };
    ASSERT_THAT(Solution().letterCombinations(s1), r1);
    string s2;
    vector<string> r2 {};
    ASSERT_THAT(Solution().letterCombinations(s2), r2);
}