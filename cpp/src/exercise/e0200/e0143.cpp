// https://leetcode-cn.com/problems/reorder-list/

#include "extern.h"

class S0143 {
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        deque<ListNode*> que;
        while (head) {
            que.push_back(head);
            head = head->next;
        }
        bool front = true; ListNode* last = nullptr, * cur;
        while (!que.empty()) {
            if (front) {
                cur = que.front();
                que.pop_front();
            }
            else {
                cur = que.back();
                que.pop_back();
            }
            if (last) last->next = cur;
            front = !front;
            last = cur;
        }
        last->next = nullptr;
    }
};

TEST(e0200, e0143) {
    ListNode* head, * ans;
    head = new ListNode("[1,2,3,4,5]");
    ans = new ListNode("[1,5,2,4,3]");
    S0143().reorderList(head);
    ASSERT_THAT(head->to_vector(), ans->to_vector());
    head = new ListNode("[1,2,3,4]");
    ans = new ListNode("[1,4,2,3]");
    S0143().reorderList(head);
    ASSERT_THAT(head->to_vector(), ans->to_vector());
}
