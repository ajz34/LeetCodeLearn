//
// Created by ajz34 on 2020/2/9.
//

#include "e0001_e0100/e0025.h"
#include "main.h"

#include <iostream>
using namespace std;

int main() {
    auto l = new ListNode({ 1, 2, 3, 4, 5 });
    cout << Solution().reverseKGroup(l, 1)->to_vector() << endl;
}