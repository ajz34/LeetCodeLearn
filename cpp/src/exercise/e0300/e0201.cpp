// https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/

#include "extern.h"

class S0201 {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == 0 || n == 0) return 0;
        if (m == n) return m;
        int div = pow(2, max(int(log2(m)), int(log2(n))));
        int result = 0;
        while (m / div == n / div) {
            if (m / div) result += div;
            m %= div, n %= div, div /= 2;
        }
        return result;
    }
};

TEST(e0300, e0201) {
    ASSERT_EQ(S0201().rangeBitwiseAnd(5, 7), 4);
    ASSERT_EQ(S0201().rangeBitwiseAnd(0, 1), 0);
}
