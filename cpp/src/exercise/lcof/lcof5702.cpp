#include "extern.h"

// ºÄÊ±£º0:09:39

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<pair<int, int>> res_pair{};
        int d = 0, l;
        while (true) {
            ++d;
            l = (2 * target / (d + 1) - d) / 2;
            if (l <= 0) break;
            if ((2 * l + d) * (d + 1) / 2 == target)
                res_pair.push_back(make_pair(l, d));
        }
        reverse(res_pair.begin(), res_pair.end());
        vector<vector<int>> result;
        for (auto& p : res_pair) {
            result.push_back({});
            vector<int>& v = result.back();
            for (int i = p.first; i <= p.first + p.second; ++i)
                v.push_back(i);
        }
        return result;
    }
};

TEST(lcof, lcof5702) {
    vector<vector<int>> ans;
    ans = str_to_mat<int>("[[2,3,4],[4,5]]");
    cout << Solution().findContinuousSequence(9) << endl;
    ans = str_to_mat<int>("[[2,3,4],[4,5]]");
    cout << Solution().findContinuousSequence(15) << endl;
}
