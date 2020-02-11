//
// Created by ajz34 on 2020/2/9.
//

#include "e0001_e0100/e0014_longest_common_prefix.h"

#include <iostream>
using namespace std;

int main() {
    vector<string> v { "flower", "flow", "flight" };
    cout << Solution().longestCommonPrefix(v) << endl;
    vector<string> l { "dog", "racecar", "car" };
    cout << Solution().longestCommonPrefix(l) << endl;
}