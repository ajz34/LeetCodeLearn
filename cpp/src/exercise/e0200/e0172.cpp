// https://leetcode-cn.com/problems/factorial-trailing-zeroes/

#include "extern.h"

class S0172 {
public:
    int trailingZeroes(int n) {
        int result = 0;
        while (n > 0) {
            result += n / 5;
            n /= 5;
        }
        return result;
    }
};

TEST(e0200, e0172) {
    ASSERT_EQ(S0172().trailingZeroes(3), 0);
    ASSERT_EQ(S0172().trailingZeroes(5), 1);
}
