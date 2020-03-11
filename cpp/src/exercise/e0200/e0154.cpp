// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/

#include "extern.h"

class S0154 {
    int findMinInner(vector<int>& nums, int l, int r) {
        if (nums[l] < nums[r - 1]) return nums[l];
        if (r - l < 4) return *min_element(nums.begin(), nums.end());
        return min(findMinInner(nums, l, (r + l) / 2), findMinInner(nums, (r + l) / 2, r));
    }
public:
    int findMin(vector<int>& nums) {
        return findMinInner(nums, 0, nums.size());
    }
};

TEST(e0200, e0154) {
    vector<int> nums;
    nums = str_to_vec<int>("[1,3,5]");
    ASSERT_EQ(S0154().findMin(nums), 1);
    nums = str_to_vec<int>("[2,2,2,0,1]");
    ASSERT_EQ(S0154().findMin(nums), 0);
}
