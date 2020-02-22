#include "extern.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return false;
        if (nums.size() == 1) return true;
        int pl = 0;
        if (nums[pl] <= 0) return false;
        if (nums[pl] >= nums.size()) return true;
        int pr = nums[pl];
        while (pr < nums.size() - 1) {
            int max_jump = 0;
            for (int p = pr; p >= pl; --p)
                max_jump = max(nums[p] - (pr - p), max_jump);
            if (max_jump <= 0) return false;
            pl = pr;
            pr = pr + max_jump;
        }
        return true;
    }
};

TEST(e0100, e0055) {
    vector<int> v = str_to_vec<int>("[2,3,1,1,4]");
    ASSERT_TRUE(Solution().canJump(v));
    v = str_to_vec<int>("[3,2,1,0,4]");
    ASSERT_FALSE(Solution().canJump(v));
}
