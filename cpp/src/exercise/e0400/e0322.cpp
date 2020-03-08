// https://leetcode-cn.com/problems/coin-change/

#include "extern.h"

class S0322 {
public:
    int coinChange(vector<int>& coins, int amount) {
        int INFTY = 10000000;
        vector<int> result(amount + 1, -1);
        result[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            int min_i = INFTY;
            for (auto c : coins) {
                if (i - c >= 0 && result[i - c] != -1)
                    min_i = min(result[i - c] + 1, min_i);
                else if (i - c < 0) continue;
            }
            result[i] = (min_i == INFTY ? -1 : min_i);
        }
        return result[amount];
    }
};

TEST(e0400, e0322) {
    vector<int> coins; int amount;
    coins = str_to_vec<int>("[1,2,5]"), amount = 11;
    ASSERT_EQ(S0322().coinChange(coins, amount), 3);
    coins = str_to_vec<int>("[2]"), amount = 3;
    ASSERT_EQ(S0322().coinChange(coins, amount), -1);
}
