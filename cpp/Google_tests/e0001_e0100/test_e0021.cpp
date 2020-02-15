//
// Created by ajz34 on 2020/2/12.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "e0001_e0100/e0021_merge_two_sorted_lists.h"
using namespace testing;

TEST(TEST_e0001_e0100, TEST_e0021) {
    auto l1 = new ListNode(vector<int>{ 1, 2, 4 });
    auto l2 = new ListNode(vector<int>{ 1, 3, 4 });
    auto l = Solution().mergeTwoLists(l1, l2);
    ASSERT_THAT(l->to_vector(), (vector<int>{ 1, 1, 2, 3, 4, 4 }));
}