#include "extern.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* pre = new ListNode(-1); pre->next = head;
        ListNode* p = pre;
        while (p && p->next) {
            if (p->next->next) {  // p->1->2->?
                auto p1 = p->next, p2 = p1->next, p3 = p2->next;
                p->next = p2; p2->next = p1; p1->next = p3;
                p = p1;
            }
            else break;
        }
        return pre->next;
    }
};

TEST(e0100, e0024) {
    auto l = new ListNode({ 1, 2, 3, 4 });
    auto ans = new ListNode({ 2, 1, 4, 3 });
    ASSERT_THAT(Solution().swapPairs(l)->to_vector(), ans->to_vector());
}
