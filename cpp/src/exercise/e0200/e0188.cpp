// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/

#include "extern.h"

typedef pair<int, int> pii;

class S0188 {
    vector<pii> gen_mono_pair(const vector<int>& prices) {
        bool flag_up = false;
        vector<pii> result;
        int left = -1;
        for (int i = 1; i < prices.size(); ++i) {
            if (!flag_up && prices[i] > prices[i - 1]) {
                left = i - 1;
                flag_up = true;
            }
            else if (flag_up && prices[i] < prices[i - 1]) {
                result.push_back({ prices[left], prices[i - 1] });
                flag_up = false;
            }
        }
        if (flag_up) result.push_back({ prices[left], prices.back() });
        return result;
    }
    vector<vector<int>> gen_up_matrix(const vector<pii>& up_vec) {
        int INF = 2147483647;
        int u_size = up_vec.size();
        vector<vector<int>> up_matrix(u_size, vector<int>(u_size, 0));
        for (int i = 0; i < u_size; ++i) {
            int u_max = -INF;
            for (int j = i; j < u_size; ++j) {
                u_max = max(up_vec[j].second, u_max);
                up_matrix[i][j] = u_max - up_vec[i].first;
            }
        }
        return up_matrix;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<pii> up_vec = gen_mono_pair(prices);
        int u_size = up_vec.size();
        if (u_size == 0) return 0;
        if (u_size < k) {
            int result = 0;
            for (auto p : up_vec)
                result += p.second - p.first;
            return result;
        }

        vector<vector<int>> up_mat = gen_up_matrix(up_vec);
        vector<vector<int>> stat(u_size, vector<int>(k + 1, 0));
        for (int i = 0; i < u_size; ++i) {
            for (int ki = 1; ki <= k; ++ki)
                stat[i][ki] = max(up_mat[0][i], stat[i][ki]);
            for (int j = i + 1; j < u_size; ++j) {
                for (int ki = 0; ki < k; ++ki) {
                    stat[j][ki + 1] = max(stat[i][ki] + up_mat[i + 1][j], stat[j][ki + 1]);
                }
            }
        }
        return stat[u_size - 1][k];
    }
};

TEST(e0200, e0188) {
    vector<int> prices; int k;
    prices = str_to_vec<int>("[2,4,1]"), k = 2;
    ASSERT_EQ(S0188().maxProfit(k, prices), 2);
    prices = str_to_vec<int>("[3,2,6,5,0,3]"), k = 2;
    ASSERT_EQ(S0188().maxProfit(k, prices), 7);
}
