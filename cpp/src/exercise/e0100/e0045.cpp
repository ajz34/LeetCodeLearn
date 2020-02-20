// https://leetcode-cn.com/problems/jump-game-ii/

#include "extern.h"

class Solution {
public:
    // TODO: This algorithm could be improve
    int jump(vector<int>& nums) {
        int pl = 0, pr = 0, result = 0;
        if (nums.size() == 1) return 0;
        while (pl < nums.size()) {
            result += 1;
            pr = pl + nums[pl];
            if (pr >= nums.size() - 1) return result;
            int max_step = 0; int max_p = 0;
            for (int p = pl + 1; p <= pr; ++p) {
                if (nums[p] - (pr - p) >= max_step) {
                    max_p = p;
                    max_step = nums[p] - (pr - p);
                }
            }
            pl = max_p;
        }
        return result;
    }
};

TEST(e0100, e0045) {
    vector<int> v = str_to_vec<int>("[2,3,1,1,4]");
    ASSERT_EQ(Solution().jump(v), 2);
}
