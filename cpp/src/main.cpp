//
// Created by ajz34 on 2020/2/9.
//

#include "e0001_e0100/e0023.h"
#include "main.h"

#include <iostream>
using namespace std;

int main() {
    vector<ListNode*> lists{ new ListNode({ 1, 4, 5 }), new ListNode({ 1, 3, 4 }), new ListNode({ 1, 2, 6 }) };
    cout << Solution().mergeKLists(lists)->to_vector() << endl;
}