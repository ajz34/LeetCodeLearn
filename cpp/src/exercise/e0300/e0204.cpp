// https://leetcode-cn.com/problems/count-primes/

#include "extern.h"

class S0204 {
public:
    int countPrimes(int n) {
        vector<bool> pb(n, true);
        int result = 0;
        int i = 2; int nsq = int(sqrt(n)) + 1;
        for (i = 2; i < nsq; ++i) {
            if (pb[i]) {
                ++result;
                for (int j = i * i; j < n; j += i)
                    pb[j] = false;
            }
        }
        for (; i < n; ++i)
            if (pb[i]) ++result;
        return result;
    }
};

TEST(e0300, e0204) {
    ASSERT_EQ(S0204().countPrimes(10), 4);
}
