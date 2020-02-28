#include "extern.h"

class Solution {
public:
    ListNode* reverseK(ListNode* pre, int k) {
        // pre -> 1 -> 2 -> 3 -> ... -> k -> k+1 ==> pre -> k -> k-1 -> ... -> 2 -> 1 -> k+1, return pr = 1
        if (k <= 1) return pre;  // None or only one node
        ListNode* p = pre->next->next->next;  // 3
        ListNode* pr = pre->next;
        // first handle pre -> 2 -> 1, 3 -> ..., where pr = 1
        pre->next = pr->next;  // construct pre -> 2
        pre->next->next = pr;  // construct 2 -> 1, however pr -> k+1 is not defined now
        //  |--------------------|
        // pre  1 <- 2 <- ... <- p-1  p -> p+1 -> p+2 -> ..., we need to let pre -> p -> p-1-> ...
        ListNode* p1 = nullptr;
        for (int i = 2; i < k; ++i) {
            p1 = p->next;  // scartch p+1
            p->next = pre->next;  // construct p -> p-1
            pre->next = p;  // construct pre -> p
            p = p1;  // let p = p+1
        }
        // finalize by pr=1 -> k+1
        pr->next = p;
        return pr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) return head;  // avoid dead-loop when k = 1
        auto pre = new ListNode(-1), p = pre;
        pre->next = head;
        while (true) {
            // find whether there are k values after pointer p
            bool success = true; auto pk = p;
            for (int i = 0; i < k; ++i) {
                if (!pk->next) { success = false; break; }
                pk = pk->next;
            }
            if (success) p = this->reverseK(p, k);
            else break;
        }
        return pre->next;
    }
};

TEST(e0100, e0025) {
    auto l = new ListNode("[1,2,3,4,5]");
    ASSERT_THAT(Solution().reverseKGroup(l, 2)->to_vector(), (vector<int>{ 2, 1, 4, 3, 5 }));
    l = new ListNode("[1,2,3,4,5]");
    ASSERT_THAT(Solution().reverseKGroup(l, 3)->to_vector(), (vector<int>{ 3, 2, 1, 4, 5 }));
    l = new ListNode("[1,2,3,4,5]");
    ASSERT_THAT(Solution().reverseKGroup(l, 1)->to_vector(), (vector<int>{ 1, 2, 3, 4, 5 }));
    l = new ListNode("[1,2,3,4,5]");
    ASSERT_THAT(Solution().reverseKGroup(l, 5)->to_vector(), (vector<int>{ 5, 4, 3, 2, 1 }));
}
