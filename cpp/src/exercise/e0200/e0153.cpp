// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/

#include "extern.h"

class S0153 {
public:
    int findMin(vector<int>& nums) {
        if (nums.front() <= nums.back())
            return nums.front();
        int l = 0, r = nums.size(), m;
        while (r - l > 4) {
            m = (r + l) / 2;
            if (nums[m] > nums[l]) l = m;
            else r = m + 1;
        }
        int result = nums[l];
        for (int i = l; i < r; ++i)
            result = min(nums[i], result);
        return result;
    }
};

TEST(e0200, e0153) {
    vector<int> nums;
    nums = str_to_vec<int>("[3,4,5,1,2]");
    ASSERT_EQ(S0153().findMin(nums), 1);
    nums = str_to_vec<int>("[4,5,6,7,0,1,2]");
    ASSERT_EQ(S0153().findMin(nums), 0);
}
