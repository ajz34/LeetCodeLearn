#include "extern.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return head;
        // get size of list
        int size = 0;
        auto p = head;
        while (p) { ++size; p = p->next; }
        int idx = size - n; p = head;
        if (idx == 0) return head->next;
        for (int i = 0; i < idx - 1; ++i) p = p->next;
        p->next = p->next->next;
        return head;
    }
};

TEST(e0100, e0019) {
    auto head = new ListNode(str_to_vec<int>("[1, 2, 3, 4, 5]"));
    auto res = Solution().removeNthFromEnd(head, 2);
    auto ans = new ListNode(str_to_vec<int>("[1, 2, 3, 5]"));
    ASSERT_THAT(res->to_vector(), ans->to_vector());
}
