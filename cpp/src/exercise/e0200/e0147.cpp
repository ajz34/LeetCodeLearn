// https://leetcode-cn.com/problems/insertion-sort-list/

#include "extern.h"

class S0147 {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        ListNode* pre = new ListNode(-1);
        ListNode* p = head, * pn = p->next, * n = pre;
        while (p) {
            pn = p->next;
            n = pre;
            bool inserted = false;
            while (n->next) {
                if (p->val < n->next->val) {
                    p->next = n->next;
                    n->next = p;
                    inserted = true;
                    break;
                }
                n = n->next;
            }
            if (!inserted) {
                n->next = p;
                p->next = nullptr;
            }
            p = pn;
        }
        return pre->next;
    }
};

TEST(e0200, e0147) {
    ListNode* node, *ans;
    node = new ListNode("[4,2,1,3]");
    ans = new ListNode("[1,2,3,4]");
    ASSERT_THAT(S0147().insertionSortList(node)->to_vector(), ans->to_vector());
    node = new ListNode("[-1,5,3,4,0]");
    ans = new ListNode("[-1,0,3,4,5]");
    ASSERT_THAT(S0147().insertionSortList(node)->to_vector(), ans->to_vector());
}
