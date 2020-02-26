// https://leetcode-cn.com/problems/partition-list/

#include "extern.h"

class S0086 {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* pre = new ListNode(0); pre->next = head;
        ListNode* pt = pre;
        while (pt && pt->next && pt->next->val < x) pt = pt->next;
        ListNode* p = pt->next;
        while (p && p->next) {
            if (p->next->val >= x) p = p->next;
            else {
                auto pt_n = pt->next, p_n = p->next, p_nn = p->next->next;
                pt->next = p->next;
                p->next->next = pt_n;
                p->next = p_nn;
                p = p_n; pt = pt->next;
            }
        }
        return pre->next;
    }
};

TEST(e0100, e0086) {
    ListNode* head; vector<int> ans;
    head = new ListNode(str_to_vec<int>("[1,4,3,2,5,2]"));
    ans = str_to_vec<int>("[1,2,2,4,3,5]");
    ASSERT_THAT(S0086().partition(head, 3)->to_vector(), ans);
}
