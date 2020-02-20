// https://leetcode-cn.com/problems/permutations-ii/

#include "extern.h"

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> vp{};
        set<vector<int>> vt{};
        for (int i = 0; i < nums.size(); ++i) {
            vt.clear();
            if (i == 0) { vp = { {nums[0]} }; continue; }
            for (int j = 0; j <= i; ++j) {
                for (auto t : vp) {
                    t.insert(t.begin() + j, nums[i]);
                    vt.insert(t);
                }
            }
            vp = vt;
        }
        return vector<vector<int>>{ vp.begin(), vp.end() };
    }
};

TEST(e0100, e0047) {
    vector<int> v = str_to_vec<int>("[1,1,2]");
    vector<vector<int>> res_mat = Solution().permuteUnique(v);
    vector<vector<int>> ans_mat = str_to_mat<int>("[\
        [1, 1, 2],\
        [1, 2, 1],\
        [2, 1, 1] \
    ]");
    set<vector<int>> res{ res_mat.begin(), res_mat.end() };
    set<vector<int>> ans{ ans_mat.begin(), ans_mat.end() };
    ASSERT_THAT(res, ans);
}
