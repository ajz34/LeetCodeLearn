// https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/

#include "extern.h"

class Solution {
public:
    int searchInt(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        if (nums.size() == 1) return nums.front() == target ? 0 : -1;
        if (nums.front() < nums.back())
            if (target < nums.front() || nums.back() < target) return -1;
        size_t is = nums.size() / 2;
        vector<int> v1 = vector<int>{ nums.cbegin(), nums.cbegin() + is };
        int i1 = searchInt(v1, target);
        if (i1 != -1) return i1;
        vector<int> v2 = vector<int>{ nums.cbegin() + is, nums.cend() };
        int i2 = searchInt(v2, target);
        return i2 == -1 ? -1 : int(is) + i2;
    }
    int search_e0081(vector<int>& nums, int target) {
        return searchInt(nums, target) == -1 ? false : true;
    }
};

TEST(e0100, e0081) {
    vector<int> vec = str_to_vec<int>("[2,5,6,0,0,1,2]");
    ASSERT_TRUE(Solution().search_e0081(vec, 0));
    ASSERT_FALSE(Solution().search_e0081(vec, 3));
}
