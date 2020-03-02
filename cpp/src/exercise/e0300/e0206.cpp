// https://leetcode-cn.com/problems/reverse-linked-list/

#include "extern.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        auto pre = new ListNode(0); pre->next = head;
        auto p = pre->next, pn = p->next, pv = pre;
        while (p) {
            pn = p->next;
            pre->next = p;
            p->next = pv;
            pv = p;
            p = pn;
        }
        head->next = nullptr;
        return pre->next;
    }
};

TEST(e0300, e0206) {
    ListNode* head, * ans;
    head = new ListNode("[1,2,3,4,5]");
    ans = new ListNode("[5,4,3,2,1]");
    ASSERT_THAT(Solution().reverseList(head)->to_vector(), ans->to_vector());
}
