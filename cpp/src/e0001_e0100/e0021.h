//
// Created by ajz34 on 2020/2/12.
//

#ifndef E0021_MERGE_TWO_SORTED_LISTS_H
#define E0021_MERGE_TWO_SORTED_LISTS_H

#include "../main.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head;
        if (!l1) return l2; if (!l2) return l1;
        if (l1->val < l2->val) { head = l1; l1 = l1->next; }
        else { head = l2; l2 = l2->next; }
        head->next = nullptr;
        auto p = head;
        while (l1 && l2) {
            if (l1->val < l2->val) { p->next = l1; l1 = l1->next; }
            else { p->next = l2; l2 = l2->next; }
            p = p->next; p->next = nullptr;
        }
        if (l1) p->next = l1;
        if (l2) p->next = l2;
        return head;
    }
};

#endif //TEST_CPP_E0021_MERGE_TWO_SORTED_LISTS_H
