// https://leetcode-cn.com/problems/sort-list/

#include "extern.h"

class S0148 {
    struct sortListCompare {
        inline bool operator()(ListNode* n1, ListNode* n2) {
            return n1->val < n2->val;
        }
    };
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return head;
        vector<ListNode*> vec;
        while (head) {
            vec.push_back(head);
            head = head->next;
        }
        sort(vec.begin(), vec.end(), sortListCompare());
        for (int i = 0; i < vec.size() - 1; ++i)
            vec[i]->next = vec[i + 1];
        vec.back()->next = nullptr;
        return vec.front();
    }
};

TEST(e0200, e0148) {
    ListNode* node, * ans;
    node = new ListNode("[4,2,1,3]");
    ans = new ListNode("[1,2,3,4]");
    ASSERT_THAT(S0148().sortList(node)->to_vector(), ans->to_vector());
    node = new ListNode("[-1,5,3,4,0]");
    ans = new ListNode("[-1,0,3,4,5]");
    ASSERT_THAT(S0148().sortList(node)->to_vector(), ans->to_vector());
}
