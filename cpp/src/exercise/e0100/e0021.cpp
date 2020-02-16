#include "extern.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head;
        if (!l1) return l2; if (!l2) return l1;
        if (l1->val < l2->val) { head = l1; l1 = l1->next; }
        else { head = l2; l2 = l2->next; }
        head->next = nullptr;
        auto p = head;
        while (l1 && l2) {
            if (l1->val < l2->val) { p->next = l1; l1 = l1->next; }
            else { p->next = l2; l2 = l2->next; }
            p = p->next; p->next = nullptr;
        }
        if (l1) p->next = l1;
        if (l2) p->next = l2;
        return head;
    }
};

TEST(e0100, e0021) {
    auto l1 = new ListNode(vector<int>{ 1, 2, 4 });
    auto l2 = new ListNode(vector<int>{ 1, 3, 4 });
    auto l = Solution().mergeTwoLists(l1, l2);
    auto res = new ListNode(vector<int>{ 1, 1, 2, 3, 4, 4 });
    ASSERT_THAT(l->to_vector(), res->to_vector());
}
