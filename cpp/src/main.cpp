//
// Created by ajz34 on 2020/2/9.
//

#include "e0001_e0100/e0024.h"
#include "main.h"

#include <iostream>
using namespace std;

int main() {
    auto l = new ListNode({ 1, 2, 3, 4 });
    cout << Solution().swapPairs(l)->to_vector() << endl;
}