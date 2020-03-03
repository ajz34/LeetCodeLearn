// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/

#include "extern.h"

class S0123 {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        vector<int> t_low, t_upp;
        bool trading = false;
        int min_v;
        for (int i = 1; i < prices.size(); ++i) {
            if (!trading) {
                if (prices[i] > prices[i - 1]) {
                    trading = true;
                    min_v = prices[i - 1];
                }
            }
            else {
                if (prices[i] < prices[i - 1]) {
                    trading = false;
                    t_low.push_back(min_v);
                    t_upp.push_back(prices[i - 1]);
                }
            }
        }
        if (trading) {
            t_low.push_back(min_v);
            t_upp.push_back(prices.back());
        }

        if (t_low.empty()) return 0;
        if (t_low.size() == 1) return t_upp[0] - t_low[0];
        int min_l = t_low.front(), max_r = t_upp.back();
        vector<int> res_low(t_low.size(), 0), res_upp(t_upp.size(), 0);
        for (int i = 0; i < t_low.size(); ++i) {
            min_l = min(t_low[i], min_l);
            if (i == 0) res_low[i] = t_upp[i] - min_l;
            else res_low[i] = max(res_low[i - 1], t_upp[i] - min_l);
        }
        for (int i = t_upp.size(); i-- > 0;) {
            max_r = max(t_upp[i], max_r);
            if (i == t_upp.size() - 1) res_upp[i] = max_r - t_low[i];
            else res_upp[i] = max(res_upp[i + 1], max_r - t_low[i]);
        }

        int result = 0;
        for (int i = 0; i < res_upp.size() - 1; ++i) {
            result = max(res_low[i] + res_upp[i + 1], result);
        }
        return result;
    }
};

TEST(e0200, e0123) {
    vector<int> prices;
    prices = str_to_vec<int>("[3,3,5,0,0,3,1,4]");
    ASSERT_EQ(S0123().maxProfit(prices), 6);
    prices = str_to_vec<int>("[1,2,3,4,5]");
    ASSERT_EQ(S0123().maxProfit(prices), 4);
    prices = str_to_vec<int>("[7,6,4,3,1]");
    ASSERT_EQ(S0123().maxProfit(prices), 0);
}
