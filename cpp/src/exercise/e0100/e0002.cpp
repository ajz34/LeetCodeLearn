#include "extern.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto head = new ListNode(0);
        auto lr = head;
        while (l1 || l2) {
            lr->next = new ListNode(0);
            if (l1) {
                lr->val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                lr->val += l2->val;
                l2 = l2->next;
            }
            if (lr->val >= 10) {
                lr->val -= 10;
                lr->next->val += 1;
            }
            lr = lr->next;
        }
        // reverse check to exclude final zero
        lr = head;
        while (lr->next->next) lr = lr->next;
        if (lr->next->val == 0) lr->next = nullptr;
        return head;
    }
};

TEST(e0100, e0002) {
    auto l1 = new ListNode(vector<int>{2, 4, 3});
    auto l2 = new ListNode(vector<int>{5, 6, 4});
    auto lr = Solution().addTwoNumbers(l1, l2);
    ASSERT_THAT(lr->to_vector(), (vector<int>{7, 0, 8}));
}
