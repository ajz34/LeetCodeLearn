// https://leetcode-cn.com/problems/linked-list-cycle-ii/

#include "extern.h"

class S0142 {
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head || !head->next) return nullptr;
        ListNode* fast = head->next, * slow = head;
        while (fast != slow) {
            if (!fast->next || !fast->next->next) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* pre = new ListNode(-1); pre->next = head;
        ListNode* p = pre;
        if (head == fast->next) return head;
        while (p->next != fast->next) {
            p = p->next;
            fast = fast->next;
        }
        return p->next;
    }
};

TEST(e0200, e0142) {
    ListNode* n0, * n1, * n2, * n3;
    n0 = new ListNode(0), n1 = new ListNode(1), n2 = new ListNode(2), n3 = new ListNode(3);
    n0->next = n1, n1->next = n2, n2->next = n3, n3->next = n1;
    ASSERT_EQ(S0142().detectCycle(n0), n1);
    n0 = new ListNode(0), n1 = new ListNode(1);
    n0->next = n1, n1->next = n0;
    ASSERT_EQ(S0142().detectCycle(n0), n0);
    n0 = new ListNode(0);
    n0->next = nullptr;
    ASSERT_EQ(S0142().detectCycle(n0), nullptr);
}
