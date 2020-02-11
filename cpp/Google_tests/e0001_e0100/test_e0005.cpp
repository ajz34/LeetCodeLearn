//
// Created by ajz34 on 2020/2/11.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "e0001_e0100/e0005_palindromic_substring.h"
using namespace testing;

TEST(TEST_e0001_e0100, TEST_e0005) {
    ASSERT_EQ(Solution().longestPalindrome("babad"), "bab");
    ASSERT_EQ(Solution().longestPalindrome("cbbd"), "bb");
    ASSERT_EQ(Solution().longestPalindrome(""), "");
    ASSERT_EQ(Solution().longestPalindrome("abcda"), "a");
}