// https://leetcode-cn.com/problems/powx-n/

#include "extern.h"

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -2147483648) {
            double f = myPow(x, n / 2);
            return f * f;
        }
        if (n < 0) return myPow(1 / x, -n);
        double f = myPow(x, n / 2);
        if (n % 2 == 0) return f * f;
        else return f * f * x;
    }
};

TEST(e0100, e0050) {
    ASSERT_DOUBLE_EQ(Solution().myPow(2., 10), 1024.);
    ASSERT_DOUBLE_EQ(Solution().myPow(2.1, 3), 9.261);
    ASSERT_DOUBLE_EQ(Solution().myPow(2., -2), 0.25);
}
