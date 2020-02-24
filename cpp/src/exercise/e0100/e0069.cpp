// https://leetcode-cn.com/problems/sqrtx/

#include "extern.h"

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        long long xl = x;
        long long l = 1, r = xl / 2 + 1;
        while (l < r) {
            long long m = (l + r) / 2;
            if (m == l) return l;
            if (m * m < xl) l = m;
            else if (m * m > xl) r = m;
            else return m;
        }
        return l;
    }
};

TEST(e0100, e0069) {
    ASSERT_EQ(Solution().mySqrt(4), 2);
    ASSERT_EQ(Solution().mySqrt(8), 2);
}
