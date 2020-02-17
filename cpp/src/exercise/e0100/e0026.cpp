// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/submissions/

#include "extern.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto pl = nums.begin();
        for (auto val : nums) {
            if (pl == nums.cbegin()) { ++pl; continue; }
            else {
                if (val == *prev(pl)) continue;
                else { *pl = val; ++pl; }
            }
        }
        return int(pl - nums.cbegin());
    }
};

TEST(e0100, e0026) {
    auto v = str_to_vec<int>("[1,1,2]");
    int res = Solution().removeDuplicates(v);
    auto ans = str_to_vec<int>("[1,2]");
    ASSERT_THAT(vector<int>(v.cbegin(), v.cbegin() + res), ans);
    v = str_to_vec<int>("[0,0,1,1,1,2,2,3,3,4]");
    res = Solution().removeDuplicates(v);
    ans = str_to_vec<int>("[0,1,2,3,4]");
    ASSERT_THAT(vector<int>(v.cbegin(), v.cbegin() + res), ans);
}
