//
// Created by ajz34 on 2020/2/12.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "e0001_e0100/e0017_letter_comb.h"
using namespace testing;

TEST(TEST_e0001_e0100, TEST_e0017) {
    string s1 = "23";
    vector<string> r1 { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" };
    ASSERT_THAT(Solution().letterCombinations(s1), r1);
    string s2;
    vector<string> r2 {};
    ASSERT_THAT(Solution().letterCombinations(s2), r2);
}