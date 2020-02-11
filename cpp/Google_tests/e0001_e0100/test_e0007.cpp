//
// Created by ajz34 on 2020/2/11.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "e0001_e0100/e0007_reverse_integer.h"
using namespace testing;

TEST(TEST_e0001_e0100, TEST_e0007) {
    ASSERT_EQ(Solution().reverse(123), 321);
    ASSERT_EQ(Solution().reverse(-1020), -201);
    ASSERT_EQ(Solution().reverse(1534236469), 0);
    ASSERT_EQ(Solution().reverse(-2147483648), 0);
}