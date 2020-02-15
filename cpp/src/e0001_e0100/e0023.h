/* 23. Merge k Sorted Lists */

#pragma once

#include "../main.h"

class Solution {

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
