//
// Created by ajz34 on 2020/2/10.
//

#include "pch.h"
#include "../../src/e0001_e0100/e0004.h"

TEST(e0001_e0100, e0004) {
    vector<int> nums1 {1, 3};
    vector<int> nums2 {2};
    ASSERT_EQ(Solution().findMedianSortedArrays(nums1, nums2), 2);
}