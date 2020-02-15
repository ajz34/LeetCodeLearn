//
// Created by ajz34 on 2020/2/10.
//

#include "pch.h"
#include "../../src/e0001_e0100/e0003.h"

TEST(e0001_e0100, e0003) {
    ASSERT_EQ(Solution().lengthOfLongestSubstring("pwwkew"), 3);
    ASSERT_EQ(Solution().lengthOfLongestSubstring(""), 0);
}