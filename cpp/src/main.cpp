//
// Created by ajz34 on 2020/2/9.
//

#include "e0001_e0100/e0002_add_two_numbers.h"
#include "main.h"

#include <vector>
using namespace std;

int main() {
    auto l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    auto l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    Solution().addTwoNumbers(l1, l2);
}