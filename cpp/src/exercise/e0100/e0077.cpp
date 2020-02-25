// https://leetcode-cn.com/problems/combinations/

#include "extern.h"

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res{ {} }, scr;
        for (int i = 1; i <= k; ++i) {
            scr.clear();
            for (auto& vs : res) {
                for (int j = (vs.empty() ? 0 : vs.back()) + 1; j <= n - (k - i); ++j) {
                    scr.push_back(vs);
                    scr.back().push_back(j);
                }
            }
            res = scr;
        }
        if (res.empty() || res.front().empty()) return {};
        return res;
    }
};

TEST(e0100, e0077) {
    auto ans = str_to_mat<int>("[[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]");
    ASSERT_THAT(Solution().combine(4, 2), ans);
}
