//
// Created by ajz34 on 2020/2/12.
//

#ifndef E0019_REMOVE_NODE_H
#define E0019_REMOVE_NODE_H

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

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

#endif //TEST_CPP_E0019_REMOVE_NODE_H
