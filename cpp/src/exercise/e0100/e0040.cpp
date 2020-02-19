#include "extern.h"

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // unordered_map<int, int> mp;  use hash table could accerlate map generation
        map<int, int> mp{};
        for (int val : candidates) {
            auto p = mp.find(val);
            if (p == mp.end()) mp[val] = 1;
            else p->second += 1;
        }
        vector<vector<vector<int>>> result(target + 1, vector<vector<int>>{});
        for (auto p : mp) {
            int s = 0; vector<int> v{};
            for (int t = 0; t < p.second; ++t) {
                s += p.first;
                if (s > target) break;
                v.push_back(p.first);
                result[s].push_back(v);
            }
            for (int s0 = target - p.first; s0 >= 0; --s0) {
                int max_p = (p.first == 0) ? p.second : min((target - s0) / p.first, p.second);
                for (auto r : result[s0]) {
                    if (r.back() == p.first) continue;
                    for (int m = 1; m <= max_p; ++m) {
                        r.push_back(p.first);
                        result[s0 + m * p.first].push_back(r);
                    }
                }
            }
        }
        return result.back();
    }
};

TEST(e0100, e0040) {
    vector<int> v = str_to_vec<int>("[10,1,2,7,6,1,5]");
    vector<vector<int>> res_mat = str_to_mat<int>("\
    [              \
        [1, 7],    \
        [1, 2, 5], \
        [2, 6],    \
        [1, 1, 6]  \
    ]");
    vector<vector<int>> ans_mat = Solution().combinationSum2(v, 8);
    set<vector<int>> ans{ ans_mat.begin(), ans_mat.end() };
    set<vector<int>> res{ res_mat.begin(), res_mat.end() };
    ASSERT_THAT(ans, res);

    v = str_to_vec<int>("[2,5,2,1,2]");
    res_mat = str_to_mat<int>("\
    [              \
        [1, 2, 2], \
        [5]        \
    ]");
    ans_mat = Solution().combinationSum2(v, 5);
    ans = { ans_mat.begin(), ans_mat.end() };
    res = { res_mat.begin(), res_mat.end() };
    ASSERT_THAT(ans, res);
}
