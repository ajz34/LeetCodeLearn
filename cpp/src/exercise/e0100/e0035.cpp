// https://leetcode-cn.com/problems/search-insert-position/

#include "extern.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto pl = nums.cbegin(), pr = nums.cend();
        while (pl < pr) {
            auto pt = pl + (pr - pl) / 2;
            if (*pt < target) pl = pt + 1;
            else if (target < *pt) pr = pt;
            else return int(pt - nums.cbegin());
        }
        assert(pl == pr);
        return int(pl - nums.cbegin());
    }
};

TEST(e0100, e0035) {
    vector<int> v = str_to_vec<int>("[1,3,5,6]");
    ASSERT_EQ(Solution().searchInsert(v, 5), 2);
    ASSERT_EQ(Solution().searchInsert(v, 2), 1);
    ASSERT_EQ(Solution().searchInsert(v, 7), 4);
    ASSERT_EQ(Solution().searchInsert(v, 0), 0);
}
