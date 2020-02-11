//
// Created by ajz34 on 2020/2/11.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "e0001_e0100/e0013_roman_to_int.h"
using namespace testing;

TEST(TEST_e0001_e0100, TEST_e0013) {
    ASSERT_EQ(Solution().romanToInt("XXVII"), 27);
    ASSERT_EQ(Solution().romanToInt("MCMXCIV"), 1994);
}