// https://leetcode-cn.com/problems/maximum-subarray/

#include "extern.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_num = -2147483648;
        int max_sum = 0, cur_sum = 0;
        for (auto num : nums) {
            max_num = max(num, max_num);
            if (cur_sum + num > 0) cur_sum += num;
            else cur_sum = 0;
            max_sum = max(cur_sum, max_sum);
        }
        if (max_num <= 0) return max_num;
        else return max_sum;
    }
};

TEST(e0100, e0053) {
    vector<int> v = str_to_vec<int>("[-2,1,-3,4,-1,2,1,-5,4]");
    ASSERT_EQ(Solution().maxSubArray(v), 6);
}
