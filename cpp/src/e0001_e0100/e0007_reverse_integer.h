//
// Created by ajz34 on 2020/2/11.
//

#ifndef E0007_REVERSE_INTEGER_H
#define E0007_REVERSE_INTEGER_H

#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long x_ = x;
        if (x_ == 0) return 0;
        bool sgn = x_ > 0; if (!sgn) x_ = -x_;
        long r = 0;
        int digit = int(log10(x_)) + 1;
        for (int i = 0; i < digit; ++i) {
            r += long(pow(10, digit - i - 1) * (x_ % 10));
            x_ /= 10;
        }
        if (r > long(pow(2, 31) - 1)) return 0;
        return sgn ? r : -r;
    }
};

#endif //TEST_CPP_E0007_REVERSE_INTEGER_H
