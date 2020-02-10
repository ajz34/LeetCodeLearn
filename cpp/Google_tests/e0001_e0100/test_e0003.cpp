//
// Created by ajz34 on 2020/2/10.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "e0001_e0100/e0003_longest_string.h"
using namespace testing;

TEST(TEST_e0001_e0100, TEST_e0003) {
    ASSERT_EQ(Solution().lengthOfLongestSubstring("pwwkew"), 3);
    ASSERT_EQ(Solution().lengthOfLongestSubstring(""), 0);
}