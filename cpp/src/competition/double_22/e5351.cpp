// https://leetcode-cn.com/problems/pizza-with-3n-slices/

#include "extern.h"

class S5351 {
    // 求从 n-1 块披萨的 slices 分割中，取出整数除法的 (n-1)/3 + 1 块披萨的最大披萨总和
    // 若 n = 11, 那么取出的披萨数量是 4 块
    int maxSizeSlicesInner(vector<int>& slices) {
        vector<vector<int>> dp(slices.size() / 3 + 1, vector<int>(slices.size(), 0));
        dp[0] = slices;
        for (int r = 1; r < dp.size(); ++r) {
            int prev_max = 0;  // 表示在 [0, 0], [0, 1], ..., [0, c-2] 区间披萨，取出不多于 r 块披萨的情形下，最大披萨总和的最大值
            for (int c = 0; c < slices.size(); ++c) {
                if (c >= 2) prev_max = max(dp[r - 1][c - 2], prev_max);
                dp[r][c] = slices[c] + prev_max;  // dp[r][c] 表示 [0, c] 区间的披萨，取出不多于 r + 1 块 (包括第 c 块) 披萨的情形下，最大披萨总和
            }
        }
        return *max_element(dp.back().begin(), dp.back().end());  // 答案即是 dp 的最后一行的最大值
    }
    int maxSizeSlicesInnerLinear(vector<int>& slices) {
        vector<int> dp_prev(slices);
        vector<int> dp_next(slices.size(), 0);
        int n = slices.size() / 3 + 1;
        for (int r = 1; r < n; ++r) {
            int prev_max = 0;
            for (int c = 0; c < slices.size(); ++c) {
                if (c >= 2) prev_max = max(dp_prev[c - 2], prev_max);
                dp_next[c] = slices[c] + prev_max;
            }
            swap(dp_prev, dp_next);
        }
        return *max_element(dp_prev.begin(), dp_prev.end());
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        vector<int> v1(slices.begin() + 1, slices.end());    // 去除第一块披萨的情形
        vector<int> v2(slices.begin(), prev(slices.end()));  // 去除最后一块披萨的情形
        return max(maxSizeSlicesInner(v1), maxSizeSlicesInner(v2));  // 取两种情形的最大值
    }
};

TEST(double22, e5351) {
    vector<int> slices;
    slices = str_to_vec<int>("[1,2,3,4,5,6]");
    ASSERT_EQ(S5351().maxSizeSlices(slices), 10);
    slices = str_to_vec<int>("[8,9,8,6,1,1]");
    ASSERT_EQ(S5351().maxSizeSlices(slices), 16);
    slices = str_to_vec<int>("[4,1,2,5,8,3,1,9,7]");
    ASSERT_EQ(S5351().maxSizeSlices(slices), 21);
    slices = str_to_vec<int>("[3,1,2]");
    ASSERT_EQ(S5351().maxSizeSlices(slices), 3);
}

/* 发布题解：化为不相邻的子数列的最大和问题，动态规划
   https://leetcode-cn.com/problems/pizza-with-3n-slices/solution/hua-wei-bu-xiang-lin-de-zi-shu-lie-de-zui-da-he-we/
*/
