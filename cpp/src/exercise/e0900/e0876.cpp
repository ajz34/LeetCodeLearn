// https://leetcode-cn.com/problems/middle-of-the-linked-list/

#include "extern.h"

class S0876 {
public:
    ListNode* middleNode(ListNode* head) {
        if (!head) return head;
        ListNode* p1 = head, * p2 = head;
        while (p2->next && p2->next->next) {
            p2 = p2->next->next;
            p1 = p1->next;
        }
        if (p2->next) return p1->next;
        else return p1;
    }
};

TEST(e0900, e0876) {
    ListNode* head;
    head = new ListNode("[1,2,3,4,5]");
    ASSERT_EQ(S0876().middleNode(head)->val, 3);
    head = new ListNode("[1,2,3,4,5,6]");
    ASSERT_EQ(S0876().middleNode(head)->val, 4);
}
