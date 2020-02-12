//
// Created by ajz34 on 2020/2/12.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "e0001_e0100/e0019_remove_node.h"
using namespace testing;

TEST(TEST_e0001_e0100, TEST_e0019) {
    auto head = new ListNode(1);
    auto p = head;
    for (int i = 2; i < 6; ++i) {
        p->next = new ListNode(i);
        p = p->next;
    }
    auto res = Solution().removeNthFromEnd(head, 2);
    for (int i : vector<int>{ 1, 2, 3, 5 }) {
        ASSERT_EQ(i, res->val);
        res = res->next;
    }
}