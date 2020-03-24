#include "extern.h"

// 耗时：10:06
// 错误：1
// 原因：零输入情况未考虑

class LCCI1716 {
public:
    int massage(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<pair<int, int>> dp(nums.size(), {0, 0});
        dp[0].second = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i].first = max(dp[i - 1].first, dp[i - 1].second);
            dp[i].second = dp[i - 1].first + nums[i];
        }
        return max(dp.back().first, dp.back().second);
    }
};

TEST(lcci, lcci1716) {
    vector<int> nums;
    nums = str_to_vec<int>("[1,2,3,1]");
    ASSERT_EQ(LCCI1716().massage(nums), 4);
    nums = str_to_vec<int>("[2,7,9,3,1]");
    ASSERT_EQ(LCCI1716().massage(nums), 12);
    nums = str_to_vec<int>("[2,1,4,5,3,1,1,3]");
    ASSERT_EQ(LCCI1716().massage(nums), 12);
}
