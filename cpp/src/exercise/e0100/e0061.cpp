// https://leetcode-cn.com/problems/rotate-list/

#include "extern.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        int len = 1; auto last = head;
        while (last->next) { ++len; last = last->next; }

        int ik = len - (k % len);
        if (ik == len) return head;

        auto p = head;
        for (int i = 0; i < ik - 1; ++i) p = p->next;
        last->next = head;
        head = p->next;
        p->next = nullptr;

        return head;
    }
};

TEST(e0100, e0061) {
    auto n = new ListNode(str_to_vec<int>("[1,2,3,4,5]"));
    auto ans = str_to_vec<int>("[4,5,1,2,3]");
    ASSERT_THAT(Solution().rotateRight(n, 2)->to_vector(), ans);
    n = new ListNode(str_to_vec<int>("[0,1,2]"));
    ans = str_to_vec<int>("[2,0,1]");
    ASSERT_THAT(Solution().rotateRight(n, 4)->to_vector(), ans);
}
