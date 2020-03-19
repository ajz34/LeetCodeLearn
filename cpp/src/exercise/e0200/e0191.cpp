// https://leetcode-cn.com/problems/number-of-1-bits/

#include "extern.h"

class S0191 {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n != 0) {
            result += n % 2;
            n /= 2;
        }
        return result;
    }
};

TEST(e0200, e0191) {
    ASSERT_EQ(S0191().hammingWeight(11), 3);
    ASSERT_EQ(S0191().hammingWeight(128), 1);
    ASSERT_EQ(S0191().hammingWeight(4294967293), 31);
}
