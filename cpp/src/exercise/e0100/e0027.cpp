// https://leetcode-cn.com/problems/remove-element/submissions/

#include "extern.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto pl = nums.begin();
        for (auto i : nums)
            if (i != val) *(pl++) = i;
        return int(pl - nums.cbegin());
    }
};

TEST(e0100, e0027) {
    auto v = str_to_vec<int>("[3,2,2,3]");
    int res = Solution().removeElement(v, 3);
    auto ans = str_to_vec<int>("[2,2]");
    ASSERT_THAT(vector<int>(v.cbegin(), v.cbegin() + res), ans);
    v = str_to_vec<int>("[0,1,2,2,3,0,4,2]");
    res = Solution().removeElement(v, 2);
    ans = str_to_vec<int>("[0,1,3,0,4]");
    ASSERT_THAT(vector<int>(v.cbegin(), v.cbegin() + res), ans);
}
