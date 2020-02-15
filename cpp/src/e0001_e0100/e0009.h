//
// Created by ajz34 on 2020/2/11.
//

#ifndef E0009_PALINDROME_NUMBER_H
#define E0009_PALINDROME_NUMBER_H

#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        int x_ = x;
        string s{};
        s.reserve(32);
        while (x_ > 0) {
            s.push_back(x_ % 10 + '0');
            x_ /= 10;
        }
        return atoi(s.c_str()) == x;
    }
};

#endif //TEST_CPP_E0009_PALINDROME_NUMBER_H
