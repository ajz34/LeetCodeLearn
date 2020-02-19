// https://leetcode-cn.com/problems/combination-sum/

#include "extern.h"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> result(target + 1, vector<vector<int>>{});
        for (int val : candidates) {
            // only current val composed vector
            int s = 0; vector<int> vec{};
            while (s + val <= target) {
                s += val;
                vec.push_back(val);
                result[s].push_back(vec);
            }
            // previous added
            for (int s0 = target - val; s0 >= 0; --s0) {
                for (auto v : result[s0]) {
                    if (v.back() == val) continue;
                    s = s0;
                    while (s + val <= target) {
                        s += val;
                        v.push_back(val);
                        result[s].push_back(v);
                    }
                }
            }
        }
        return result.back();
    }
};

TEST(e0100, e0039) {
    vector<int> v = str_to_vec<int>("[2,3,6,7]");
    vector<vector<int>> res_mat = str_to_mat<int>("\
    [             \
        [7],      \
        [2, 2, 3] \
    ]");
    vector<vector<int>> ans_mat = Solution().combinationSum(v, 7);
    set<vector<int>> ans{ ans_mat.begin(), ans_mat.end() };
    set<vector<int>> res{ res_mat.begin(), res_mat.end() };
    ASSERT_THAT(ans, res);

    v = str_to_vec<int>("[2,3,5]");
    res_mat = str_to_mat<int>("\
    [                 \
        [2, 2, 2, 2], \
        [2, 3, 3],    \
        [3, 5]        \
    ]");
    ans_mat = Solution().combinationSum(v, 8);
    ans = { ans_mat.begin(), ans_mat.end() };
    res = { res_mat.begin(), res_mat.end() };
    ASSERT_THAT(ans, res);
}
