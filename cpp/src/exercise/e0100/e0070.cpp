// https://leetcode-cn.com/problems/climbing-stairs/

#include "extern.h"

class Solution {
public:
    int climbStairs(int n) {
        int n1 = 1, n2 = 1;
        for (int i = 1; i < n; ++i) {
            n1 += n2;
            swap(n1, n2);
        }
        return n2;
    }
};

TEST(e0100, e0070) {
    ASSERT_EQ(Solution().climbStairs(2), 2);
    ASSERT_EQ(Solution().climbStairs(3), 3);
}
