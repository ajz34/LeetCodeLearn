// https://leetcode-cn.com/problems/permutations/

#include "extern.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vp{};
        vector<vector<int>> vt{};
        for (int i = 0; i < nums.size(); ++i) {
            vt.clear();
            if (i == 0) { vp = { {nums[0]} }; continue; }
            for (int j = 0; j <= i; ++j) {
                for (auto t : vp) {
                    t.insert(t.begin() + j, nums[i]);
                    vt.push_back(t);
                }
            }
            vp = vt;
        }
        return vp;
    }
};

TEST(e0100, e0046) {
    vector<int> v = str_to_vec<int>("[1,2,3]");
    vector<vector<int>> res_mat = Solution().permute(v);
    vector<vector<int>> ans_mat = str_to_mat<int>("[\
        [1, 2, 3], \
        [1, 3, 2], \
        [2, 1, 3], \
        [2, 3, 1], \
        [3, 1, 2], \
        [3, 2, 1]  \
    ]");
    set<vector<int>> res{ res_mat.begin(), res_mat.end() };
    set<vector<int>> ans{ ans_mat.begin(), ans_mat.end() };
    ASSERT_THAT(res, ans);
}
