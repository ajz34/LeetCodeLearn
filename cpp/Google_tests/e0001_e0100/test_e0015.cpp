//
// Created by ajz34 on 2020/2/11.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "e0001_e0100/e0015_three_sum.h"
using namespace testing;

TEST(TEST_e0001_e0100, TEST_e0015) {
    vector<int> v1{ -1, 0, 1, 2, -1, -4 };
    vector<vector<int>> r1{ { -1, -1, 2 }, { -1, 0, 1 } };
    ASSERT_THAT(Solution().threeSum(v1), r1);
    vector<int> v2{ 0, 0, 0 };
    vector<vector<int>> r2{ { 0, 0, 0 } };
    ASSERT_THAT(Solution().threeSum(v2), r2);
    vector<int> v3{};
    vector<vector<int>> r3{};
    ASSERT_THAT(Solution().threeSum(v3), r3);
}