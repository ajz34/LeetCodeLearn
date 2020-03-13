// https://leetcode-cn.com/problems/find-peak-element/

#include "extern.h"

class S0162 {
public:
    int findPeakElement(vector<int>& nums) {
        int s = nums.size();
        if (s == 1) return 0;
        int l = 0, r = s - 1, m;
        if (nums[0] > nums[1]) return 0;
        if (nums[s - 1] > nums[s - 2]) return s - 1;
        while (r - l > 1) {
            m = l + (r - l) / 2;
            if (nums[m] < nums[m - 1]) swap(m, r);
            else if (nums[m] < nums[m + 1]) swap(m, l);
            else return m;
        }
        assert(false);
        return -1;
    }
};

TEST(e0200, e0162) {
    vector<int> nums; int res; set<int> ans;
    nums = str_to_vec<int>("[1,2,3,1]");
    res = S0162().findPeakElement(nums);
    ans = set<int>{ 2 };
    ASSERT_TRUE(ans.find(res) != ans.end());
    nums = str_to_vec<int>("[1,2,1,3,5,6,4]");
    res = S0162().findPeakElement(nums);
    ans = set<int>{ 1, 5 };
    ASSERT_TRUE(ans.find(res) != ans.end());
}
