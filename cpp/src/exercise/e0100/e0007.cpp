#include "extern.h"

class Solution {
public:
    int reverse(int x) {
        long long x_ = x;
        if (x_ == 0) return 0;
        bool sgn = x_ > 0; if (!sgn) x_ = -x_;
        long long r = 0;
        int digit = int(log10(x_)) + 1;
        for (int i = 0; i < digit; ++i) {
            r += (long long)(pow(10, digit - i - 1) * (x_ % 10));
            x_ /= 10;
        }
        if (r > (long long)(pow(2, 31) - 1)) return 0;
        return sgn ? r : -r;
    }
};

TEST(e0100, e0007) {
    ASSERT_EQ(Solution().reverse(123), 321);
    ASSERT_EQ(Solution().reverse(-1020), -201);
    ASSERT_EQ(Solution().reverse(1534236469), 0);
    ASSERT_EQ(Solution().reverse(-2147483648), 0);
}
