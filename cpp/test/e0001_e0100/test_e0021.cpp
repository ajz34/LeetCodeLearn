//
// Created by ajz34 on 2020/2/12.
//

#include "pch.h"
#include "../../src/e0001_e0100/e0021.h"

TEST(e0001_e0100, e0021) {
    auto l1 = new ListNode(vector<int>{ 1, 2, 4 });
    auto l2 = new ListNode(vector<int>{ 1, 3, 4 });
    auto l = Solution().mergeTwoLists(l1, l2);
    ASSERT_THAT(l->to_vector(), (vector<int>{ 1, 1, 2, 3, 4, 4 }));
}