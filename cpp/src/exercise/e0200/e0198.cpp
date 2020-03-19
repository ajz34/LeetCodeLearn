// https://leetcode-cn.com/problems/house-robber/

#include "extern.h"

class S0198 {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> res(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            res[i] = nums[i];
            if (i - 2 >= 0) res[i] = max(nums[i] + res[i - 2], res[i]);
            if (i - 3 >= 0) res[i] = max(nums[i] + res[i - 3], res[i]);
        }
        int result = 0;
        for (int i = max(int(nums.size() - 4), 0); i < nums.size(); ++i)
            result = max(res[i], result);
        return result;
    }
};

TEST(e0200, e0198) {
    vector<int> nums;
    nums = str_to_vec<int>("[1,2,3,1]");
    ASSERT_EQ(S0198().rob(nums), 4);
    nums = str_to_vec<int>("[2,7,9,3,1]");
    ASSERT_EQ(S0198().rob(nums), 12);
}
