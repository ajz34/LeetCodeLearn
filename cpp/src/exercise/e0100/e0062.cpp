// https://leetcode-cn.com/problems/unique-paths/

#include "extern.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
        // C_b^a, where b = m + n - 2, a = min(m - 1, n - 1);
        int a = min(m - 1, n - 1);
        int b = m + n - 2;
        long long result = 1;
        for (int i = 0; i < a; ++i) result *= (b - i);
        for (int i = 0; i < a; ++i) result /= (a - i);
        return int(result);
    }
};

TEST(e0100, e0062) {
    ASSERT_EQ(Solution().uniquePaths(3, 2), 3);
    ASSERT_EQ(Solution().uniquePaths(7, 3), 28);
}
