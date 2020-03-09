// https://leetcode-cn.com/problems/linked-list-cycle/

#include "extern.h"

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) return false;
        ListNode* p = nullptr, * pn = head, * pnn;
        while (pn) {
            pnn = pn->next;
            pn->next = p;
            p = pn;
            pn = pnn;
        }
        return p == head;
    }
};

TEST(e0200, e0141) {
    ListNode* n0, * n1, * n2, * n3;
    n0 = new ListNode(0), n1 = new ListNode(1), n2 = new ListNode(2), n3 = new ListNode(3);
    n0->next = n1, n1->next = n2, n2->next = n3, n3->next = n1;
    ASSERT_TRUE(Solution().hasCycle(n0));
    n0 = new ListNode(0), n1 = new ListNode(1);
    n0->next = n1, n1->next = n0;
    ASSERT_TRUE(Solution().hasCycle(n0));
    n0 = new ListNode(0);
    n0->next = nullptr;
    ASSERT_FALSE(Solution().hasCycle(n0));
}
