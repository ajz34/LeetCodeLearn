//
// Created by ajz34 on 2020/2/11.
//

#include "pch.h"
#include "../../src/e0001_e0100/e0010.h"

TEST(e0001_e0100, e0010) {
    ASSERT_FALSE(Solution().isMatch("aa", "a"));
    ASSERT_TRUE(Solution().isMatch("aa", "a*"));
    ASSERT_TRUE(Solution().isMatch("ab", ".*"));
    ASSERT_TRUE(Solution().isMatch("aab", "c*a*b"));
    ASSERT_FALSE(Solution().isMatch("mississippi", "mis*is*p*."));
    ASSERT_TRUE(Solution().isMatch("mississippi", "mis*is*ip*."));
    ASSERT_FALSE(Solution().isMatch("ab", ".*c"));
    ASSERT_TRUE(Solution().isMatch("a", "ab*"));
    ASSERT_TRUE(Solution().isMatch("", "c*c*"));
    ASSERT_FALSE(Solution().isMatch("a", "..a"));
}