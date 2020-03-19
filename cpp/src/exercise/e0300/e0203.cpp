// https://leetcode-cn.com/problems/remove-linked-list-elements/

#include "extern.h"

class S0203 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre = new ListNode(-1); pre->next = head;
        ListNode* node = pre;
        while (node && node->next) {
            if (node->next->val == val)
                node->next = node->next->next;
            else
                node = node->next;
        }
        return pre->next;
    }
};

TEST(e0300, e0203) {
    ListNode* head, * ans;
    head = new ListNode("[1,2,6,3,4,5,6]");
    ans = new ListNode("[1,2,3,4,5]");
    ASSERT_THAT(S0203().removeElements(head, 6)->to_vector(), ans->to_vector());
}
