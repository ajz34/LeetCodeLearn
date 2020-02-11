//
// Created by ajz34 on 2020/2/9.
//

#include "e0001_e0100/e0007_reverse_integer.h"

#include <iostream>
using namespace std;

int main() {
    cout << Solution().reverse(-123) << endl;
    cout << Solution().reverse(-1020) << endl;
    cout << Solution().reverse(1534236469) << endl;
    cout << Solution().reverse(-2147483648) << endl;
}