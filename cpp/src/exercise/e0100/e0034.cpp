// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include "extern.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // exclude extreme situation
        if (nums.empty()) return vector<int>{ -1, -1 };
        if (nums.size() == 1) return (target == nums.front()) ? vector<int>{ 0, 0 } : vector<int>{ -1, -1 };
        // start
        auto pll = nums.cbegin(), plr = nums.cend();
        auto prl = pll, prr = plr;
        // search smallest index
        auto pt = pll;
        int res_l = -1, res_r = -1;
        while (pll < plr) {
            pt = pll + (plr - pll) / 2;
            if (target < *pt) prr = plr = pt;
            else if (*pt < target) prl = pll = pt + 1;
            else if (pt - nums.cbegin() > 0 && *(pt - 1) != target) { res_l = int(pt - nums.cbegin()); break; }
            else if (pt == nums.cbegin()) { res_l = 0; break; }
            else { plr = prl = pt; }
        }
        if (res_l == -1) return { -1, -1 };
        while (prl < prr) {
            pt = prl + (prr - prl) / 2;
            if (target < *pt) prr = pt;
            else if (pt != nums.cend() - 1 && *(pt + 1) != target) { res_r = int(pt - nums.cbegin()); break; }
            else if (pt == nums.cend() - 1) { res_r = int(nums.size() - 1); break; }
            else { prl = pt + 1; }
        }
        return { res_l, res_r };
    }
};

TEST(e0100, e0034) {
    vector<int> v = str_to_vec<int>("[5,7,7,8,8,10]");
    ASSERT_THAT(Solution().searchRange(v, 8), str_to_vec<int>("[3,4]"));
    ASSERT_THAT(Solution().searchRange(v, 6), str_to_vec<int>("[-1,-1]"));
}
