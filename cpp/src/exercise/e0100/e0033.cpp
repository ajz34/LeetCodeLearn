// https://leetcode-cn.com/problems/search-in-rotated-sorted-array/

#include "extern.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        if (nums.size() == 1) return nums.front() == target ? 0 : -1;
        if (nums.front() <= nums.back())
            if (target < nums.front() || nums.back() < target) return -1;
        size_t is = nums.size() / 2;
        vector<int> v1 = vector<int>{ nums.cbegin(), nums.cbegin() + is };
        int i1 = search(v1, target);
        if (i1 != -1) return i1;
        vector<int> v2 = vector<int>{ nums.cbegin() + is, nums.cend() };
        int i2 = search(v2, target);
        return i2 == -1 ? -1 : int(is) + i2;
    }
};

TEST(e0100, e0033) {
    vector<int> v = str_to_vec<int>("[4,5,6,7,0,1,2]");
    ASSERT_EQ(Solution().search(v, 0), 4);
    ASSERT_EQ(Solution().search(v, 3), -1);
}