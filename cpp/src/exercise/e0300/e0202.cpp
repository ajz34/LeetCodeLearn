// https://leetcode-cn.com/problems/happy-number/

#include "extern.h"

class S0202 {
    int process(int n) {
        int result = 0;
        while (n != 0) {
            result += (n % 10) * (n % 10);
            n /= 10;
        }
        return result;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> traj;
        while (traj.find(n) == traj.end()) {
            traj.insert(n);
            n = process(n);
            if (n == 1) return true;
        }
        return false;
    }
};

TEST(e0300, e0202) {
    ASSERT_TRUE(S0202().isHappy(19));
}
