//
// Created by ajz34 on 2020/2/12.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "e0001_e0100/e0016_three_sum_closest.h"
using namespace testing;

TEST(TEST_e0001_e0100, TEST_e0016) {
    vector<int> v{ -1, 2, 1, -4 };
    ASSERT_EQ(Solution().threeSumClosest(v, 1), 2);
}