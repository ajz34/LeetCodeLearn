// https://leetcode-cn.com/problems/subsets/

#include "extern.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) return { {} };
        int back = nums.back(); nums.pop_back();
        vector<vector<int>> result = subsets(nums);
        size_t r_size = result.size();
        for (size_t i = 0; i < r_size; ++i) {
            auto v{ result[i] };
            v.push_back(back);
            result.push_back(v);
        }
        return result;
    }
};

TEST(e0100, e0078) {
    auto nums = str_to_vec<int>("[1,2,3]");
    auto res_mat = Solution().subsets(nums);
    auto ans_mat = str_to_mat<int>("[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]");
    auto res = set<vector<int>>(res_mat.begin(), res_mat.end());
    auto ans = set<vector<int>>(ans_mat.begin(), ans_mat.end());
    ASSERT_THAT(res, ans);
}
