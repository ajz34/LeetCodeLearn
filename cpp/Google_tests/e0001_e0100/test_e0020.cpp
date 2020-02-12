//
// Created by ajz34 on 2020/2/12.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "e0001_e0100/e0020_valid_parenthese.h"
using namespace testing;

TEST(TEST_e0001_e0100, TEST_e0020) {
    ASSERT_TRUE(Solution().isValid("()"));
    ASSERT_TRUE(Solution().isValid("((([]){}))"));
    ASSERT_FALSE(Solution().isValid("(]"));
    ASSERT_FALSE(Solution().isValid("){"));
}