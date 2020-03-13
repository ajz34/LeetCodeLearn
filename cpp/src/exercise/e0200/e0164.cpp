// https://leetcode-cn.com/problems/maximum-gap/

#include "extern.h"

class S0164 {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        sort(nums.begin(), nums.end());
        int gap = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
            gap = max(gap, nums[i + 1] - nums[i]);
        return gap;
    }
};

TEST(e0200, e0164) {
    vector<int> vec;
    vec = str_to_vec<int>("[3,6,9,1]");
    ASSERT_EQ(S0164().maximumGap(vec), 3);
    vec = str_to_vec<int>("[10]");
    ASSERT_EQ(S0164().maximumGap(vec), 0);
}
