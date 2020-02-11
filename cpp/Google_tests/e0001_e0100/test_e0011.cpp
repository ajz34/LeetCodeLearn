//
// Created by ajz34 on 2020/2/11.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "e0001_e0100/e0011_contain_most_water.h"
using namespace testing;

TEST(TEST_e0001_e0100, TEST_e0011) {
    vector<int> v{ 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    ASSERT_EQ(Solution().maxArea(v), 49);
}