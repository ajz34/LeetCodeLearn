//
// Created by ajz34 on 2020/2/9.
//

#include "e0001_e0100/e0008_string_to_integer.h"

#include <iostream>
using namespace std;

int main() {
    cout << Solution().myAtoi("42") << endl;
    cout << Solution().myAtoi("   -42") << endl;
    cout << Solution().myAtoi("4193 with words") << endl;
    cout << Solution().myAtoi("words and 987") << endl;
    cout << Solution().myAtoi("-91283472332") << endl;
    cout << Solution().myAtoi("  0000000000012345678") << endl;
    cout << Solution().myAtoi("000000000000000000") << endl;
    cout << Solution().myAtoi("+") << endl;
    cout << Solution().myAtoi("20000000000000000000") << endl;
}