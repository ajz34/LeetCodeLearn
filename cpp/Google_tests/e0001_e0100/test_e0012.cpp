//
// Created by ajz34 on 2020/2/11.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "e0001_e0100/e0012_int_to_roman.h"
using namespace testing;

TEST(TEST_e0001_e0100, TEST_e0012) {
    ASSERT_EQ(Solution().intToRoman(27), "XXVII");
    ASSERT_EQ(Solution().intToRoman(1994), "MCMXCIV");
}