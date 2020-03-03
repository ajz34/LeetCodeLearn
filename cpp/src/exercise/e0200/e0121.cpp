// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/

#include "extern.h"

class S0121 {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int min_v = 2147483647, result = 0;
        for (auto p : prices) {
            if (p <= min_v) min_v = p;
            else result = max(p - min_v, result);
        }
        return result;
    }
};

TEST(e0200, e0121) {
    vector<int> prices;
    prices = str_to_vec<int>("[7,1,5,3,6,4]");
    ASSERT_EQ(S0121().maxProfit(prices), 5);
    prices = str_to_vec<int>("[7,6,4,3,1]");
    ASSERT_EQ(S0121().maxProfit(prices), 0);
}
