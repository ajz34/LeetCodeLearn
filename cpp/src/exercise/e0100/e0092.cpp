// https://leetcode-cn.com/problems/reverse-linked-list-ii/

#include "extern.h"

class S0092 {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (n - m == 0) return head;
        auto pre = new ListNode(0); pre->next = head;
        ListNode* p = pre; ListNode(*pi), (*p_n), (*pi_n);
        for (int i = 0; i < m - 1; ++i) p = p->next;
        p_n = p->next; pi = p_n;
        for (int i = 0; i < n - m; ++i) {
            pi_n = (i == 0 ? pi->next : p_n->next);
            p->next = pi_n;
            p_n->next = pi_n->next;
            pi_n->next = pi;
            pi = p->next;
        }
        return pre->next;
    }
};

TEST(e0100, e0092) {
    ListNode *head, *ans;
    head = new ListNode(str_to_vec<int>("[1,2,3,4,5]"));
    ans = new ListNode(str_to_vec<int>("[1,4,3,2,5]"));
    ASSERT_THAT(S0092().reverseBetween(head, 2, 4)->to_vector(), ans->to_vector());
}
