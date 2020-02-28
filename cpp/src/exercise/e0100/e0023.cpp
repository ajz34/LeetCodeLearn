#include "extern.h"

class S0023 {

    struct ListNodeLess {
        inline bool operator()(const ListNode* l1, const ListNode* l2) const { return l1->val < l2->val; }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<ListNode*, ListNodeLess> min_nodes{};
        ListNode* head = nullptr;
        ListNode* p = nullptr;
        // 0. insert first node to min_nodes
        for (auto l : lists) if (l) min_nodes.insert(l);
        // 1. loop, append every minimum ListNode l to the result list
        while (!min_nodes.empty()) {
            if (!head) {
                head = p = *min_nodes.begin();
            }
            else {
                p->next = *min_nodes.begin();
                p = p->next;
            }
            min_nodes.erase(min_nodes.begin());
            if (p->next) min_nodes.insert(p->next);
        }
        return head;
    }
};

TEST(e0100, e0023) {
    vector<ListNode*> lists{ new ListNode("[1,4,5]"), new ListNode("[1,3,4]"), new ListNode("[2,6]") };
    auto ans = new ListNode("[1,1,2,3,4,4,5,6]");
    ASSERT_THAT(S0023().mergeKLists(lists)->to_vector(), ans->to_vector());
}
