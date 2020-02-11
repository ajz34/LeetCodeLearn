//
// Created by ajz34 on 2020/2/11.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "e0001_e0100/e0014_longest_common_prefix.h"
using namespace testing;

TEST(TEST_e0001_e0100, TEST_e0014) {
    vector<string> v { "flower", "flow", "flight" };
    ASSERT_EQ(Solution().longestCommonPrefix(v), "fl");
    vector<string> l { "dog", "racecar", "car" };
    ASSERT_EQ(Solution().longestCommonPrefix(l), "");
}