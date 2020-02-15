//
// Created by ajz34 on 2020/2/11.
//

#include "pch.h"
#include "../../src/e0001_e0100/e0005.h"

TEST(e0001_e0100, e0005) {
    ASSERT_EQ(Solution().longestPalindrome("babad"), "bab");
    ASSERT_EQ(Solution().longestPalindrome("cbbd"), "bb");
    ASSERT_EQ(Solution().longestPalindrome(""), "");
    ASSERT_EQ(Solution().longestPalindrome("abcda"), "a");
}