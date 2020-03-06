// https://leetcode-cn.com/problems/single-number/

#include "extern.h"

class S0136 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> s;
        while (!nums.empty()) {
            s[nums.back()] += 1;
            nums.pop_back();
        }
        for (auto p : s)
            if (p.second == 1) return p.first;
        return 0;
    }
};

TEST(e0200, e0136) {
    vector<int> nums;
    nums = str_to_vec<int>("[2,2,1]");
    ASSERT_EQ(S0136().singleNumber(nums), 1);
    nums = str_to_vec<int>("[4,2,1,2,1]");
    ASSERT_EQ(S0136().singleNumber(nums), 4);
}
