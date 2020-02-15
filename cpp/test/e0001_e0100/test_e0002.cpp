//
// Created by ajz34 on 2020/2/10.
//

#include "pch.h"
#include "../../src/e0001_e0100/e0002.h"

TEST(e0001_e0100, e0002) {
    auto l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    auto l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    auto lr = Solution().addTwoNumbers(l1, l2);
    ASSERT_EQ(lr->val, 7);
    ASSERT_EQ(lr->next->val, 0);
    ASSERT_EQ(lr->next->next->val, 8);
}
