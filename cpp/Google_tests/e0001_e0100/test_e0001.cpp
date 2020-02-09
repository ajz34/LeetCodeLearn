//
// Created by ajz34 on 2020/2/9.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "e0001_e0100/e0001_two_sum.h"
using namespace testing;

TEST(TEST_e0001_e0100, TEST_e0001) {
    auto vec = vector<int>{ 2, 7, 11, 15 };
    auto sol = Solution().twoSum(vec, 9);
    ASSERT_THAT(sol, ElementsAre(0, 1));
}
