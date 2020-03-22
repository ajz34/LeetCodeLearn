// https://leetcode-cn.com/problems/water-and-jug-problem/

#include "extern.h"

class S0365 {
    int gcd(int x, int y) {
        int l = max(x, y), r = min(x, y);
        while (y != 0) {
            x %= y;
            swap(x, y);
        }
        return x;
    }
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x == 0 && y == 0) return z == 0;
        int r = gcd(x, y);
        return (z % r == 0) && (z <= x + y) && (z >= 0);
    }
};

TEST(e0400, e0365) {
    ASSERT_TRUE(S0365().canMeasureWater(3, 5, 4));
    ASSERT_FALSE(S0365().canMeasureWater(2, 6, 5));
}
