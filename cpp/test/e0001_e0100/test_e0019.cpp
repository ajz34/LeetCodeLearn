//
// Created by ajz34 on 2020/2/12.
//

#include "pch.h"
#include "../../src/e0001_e0100/e0019.h"

TEST(e0001_e0100, e0019) {
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