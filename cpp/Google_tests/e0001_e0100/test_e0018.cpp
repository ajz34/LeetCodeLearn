//
// Created by ajz34 on 2020/2/12.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "e0001_e0100/e0018_four_sum.h"
using namespace testing;

TEST(TEST_e0001_e0100, TEST_e0018) {
    vector<int> v { 1, 0, -1, 0, -2, 2 };
    vector<vector<int>> r {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
    ASSERT_THAT(Solution().fourSum(v, 0), r);
}