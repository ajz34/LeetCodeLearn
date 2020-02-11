//
// Created by ajz34 on 2020/2/9.
//

#include "e0001_e0100/e0010_reg_expr_match.h"

#include <iostream>
using namespace std;

int main() {
    cout << Solution().isMatch("aa", "a") << endl;
    cout << Solution().isMatch("aa", "a*") << endl;
    cout << Solution().isMatch("ab", ".*") << endl;
    cout << Solution().isMatch("aab", "c*a*b") << endl;
    cout << Solution().isMatch("mississippi", "mis*is*p*.") << endl;
    cout << Solution().isMatch("mississippi", "mis*is*ip*.") << endl;
    cout << Solution().isMatch("ab", ".*c") << endl;
    cout << Solution().isMatch("a", "ab*") << endl;
    cout << Solution().isMatch("", "c*c*") << endl;
    cout << Solution().isMatch("a", "..a") << endl;
}