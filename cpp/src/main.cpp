//
// Created by ajz34 on 2020/2/9.
//

#include "e0001_e0100/e0019_remove_node.h"

#include <iostream>
using namespace std;

int main() {
    auto head = new ListNode(1);
    auto p = head;
    for (int i = 2; i < 6; ++i) {
        p->next = new ListNode(i);
        p = p->next;
    }
    auto res = Solution().removeNthFromEnd(head, 5);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
}