// https://leetcode-cn.com/problems/majority-element/

#include "extern.h"

class S0169 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i : nums) mp[i] += 1;
        for (auto& p : mp) if (p.second > nums.size() / 2) return p.first;
        return -1;
    }
};

TEST(e0200, e0169) {
    vector<int> nums;
    nums = str_to_vec<int>("[3,2,3]");
    ASSERT_EQ(S0169().majorityElement(nums), 3);
    nums = str_to_vec<int>("[2,2,1,1,1,2,2]");
    ASSERT_EQ(S0169().majorityElement(nums), 2);
}
