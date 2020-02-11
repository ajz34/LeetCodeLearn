//
// Created by ajz34 on 2020/2/11.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "e0001_e0100/e0006_zigzag_conversion.h"
using namespace testing;

TEST(TEST_e0001_e0100, TEST_e0006) {
    ASSERT_EQ(Solution().convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
    ASSERT_EQ(Solution().convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
    ASSERT_EQ(Solution().convert("A", 1), "A");
}