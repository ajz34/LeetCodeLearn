// https://leetcode-cn.com/problems/reverse-bits/

#include "extern.h"

class S0190 {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result *= 2;
            result += n % 2;
            n /= 2;
        }
        return result;
    }
};

TEST(e0200, e0190) {
    ASSERT_EQ(S0190().reverseBits(uint32_t(43261596)), uint32_t(964176192));
    ASSERT_EQ(S0190().reverseBits(uint32_t(4294967293)), uint32_t(3221225471));
}
