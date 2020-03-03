// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/

#include "extern.h"

class S0122 {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int min_v = prices.front();
        int result = 0;
        bool trading = true;
        for (int i = 1; i < prices.size(); ++i) {
            if (trading) {
                if (prices[i] < prices[i - 1]) {
                    result += prices[i - 1] - min_v;
                    trading = false;
                }
            }
            else {
                if (prices[i] > prices[i - 1]) {
                    min_v = prices[i - 1];
                    trading = true;
                }
            }
        }
        if (trading) result += prices.back() - min_v;
        return result;
    }
};

TEST(e0200, e0122) {
    vector<int> prices;
    prices = str_to_vec<int>("[7,1,5,3,6,4]");
    ASSERT_EQ(S0122().maxProfit(prices), 7);
    prices = str_to_vec<int>("[1,2,3,4,5]");
    ASSERT_EQ(S0122().maxProfit(prices), 4);
    prices = str_to_vec<int>("[7,6,4,3,1]");
    ASSERT_EQ(S0122().maxProfit(prices), 0);
}
