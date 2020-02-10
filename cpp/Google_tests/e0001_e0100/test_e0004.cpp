//
// Created by ajz34 on 2020/2/10.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "e0001_e0100/e0004_array_median.h"
using namespace testing;

TEST(TEST_e0001_e0100, TEST_e0001) {
    vector<int> nums1 {1, 3};
    vector<int> nums2 {2};
    ASSERT_EQ(Solution().findMedianSortedArrays(nums1, nums2), 2);
}