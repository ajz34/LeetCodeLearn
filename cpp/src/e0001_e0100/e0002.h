//
// Created by ajz34 on 2020/2/10.
//

#ifndef E0002_ADD_TWO_NUMBERS_H
#define E0002_ADD_TWO_NUMBERS_H

#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

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

#endif //TEST_CPP_E0002_ADD_TWO_NUMBERS_H
