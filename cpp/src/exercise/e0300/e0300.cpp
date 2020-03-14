// https://leetcode-cn.com/problems/longest-increasing-subsequence/

#include "extern.h"

class S0300 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        vector<int> stat{ 1 };
        int max_v = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int v = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i])
                    v = max(v, stat[j] + 1);
            }
            stat.push_back(v);
            max_v = max(v, max_v);
        }
        return max_v;
    }
};

TEST(e0300, e0300) {
    vector<int> nums;
    nums = str_to_vec<int>("[10,9,2,5,3,7,101,18]");
    ASSERT_EQ(S0300().lengthOfLIS(nums), 4);
}
