// https://leetcode-cn.com/problems/candy/

#include "extern.h"

class S0135 {
    int argmin(vector<int>& vec, int l, int r) {
        int value = vec[l] + 1, arg = 0;
        for (int i = l; i < r; ++i) {
            if (vec[i] < value) {
                value = vec[i];
                arg = i;
            }
        }
        return arg;
    }
    void candyInner(vector<int>& ratings, int l, int r, vector<int>& cost) {
        if (r <= l) return;
        int m = argmin(ratings, l, r);
        int nl, nr;
        cost[m] = 1;
        for (nl = m - 1; nl >= 0; --nl) {
            if (ratings[nl] > ratings[nl + 1])
                cost[nl] = max(cost[nl + 1] + 1, cost[nl]);
            else break;
        }
        for (nr = m + 1; nr < cost.size(); ++nr) {
            if (ratings[nr] > ratings[nr - 1])
                cost[nr] = max(cost[nr - 1] + 1, cost[nr]);
            else break;
        }
        candyInner(ratings, l, nl + 1, cost);
        candyInner(ratings, nr, r, cost);
    }
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) return 0;
        vector<int> cost(ratings.size(), 0);
        candyInner(ratings, 0, ratings.size(), cost);
        return accumulate(cost.begin(), cost.end(), 0);
    }
};

TEST(e0200, e0135) {
    vector<int> ratings;
    ratings = str_to_vec<int>("[1,0,2]");
    ASSERT_EQ(S0135().candy(ratings), 5);
    ratings = str_to_vec<int>("[1,2,2]");
    ASSERT_EQ(S0135().candy(ratings), 4);
}
