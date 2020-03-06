// https://leetcode-cn.com/problems/single-number-ii/

#include "extern.h"

class S0137 {
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

TEST(e0200, e0137) {
    vector<int> nums;
    nums = str_to_vec<int>("[2,2,3,2]");
    ASSERT_EQ(S0137().singleNumber(nums), 3);
    nums = str_to_vec<int>("[0,1,0,1,0,1,99]");
    ASSERT_EQ(S0137().singleNumber(nums), 99);
}
