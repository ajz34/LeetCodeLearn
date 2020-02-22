// https://leetcode-cn.com/problems/insert-interval/

#include "extern.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto p = lower_bound(intervals.begin(), intervals.end(), newInterval, [](const vector<int>& v1, const vector<int>& v2) { return v1[0] < v2[0]; });
        intervals.insert(p, newInterval);
        vector<int> cur_v;
        vector<vector<int>> result;
        for (auto& v : intervals) {
            if (cur_v.empty()) cur_v = v;
            else if (v[0] <= cur_v[1]) cur_v[1] = max(v[1], cur_v[1]);
            else { result.push_back(cur_v); cur_v = v; }
        }
        if (!cur_v.empty()) result.push_back(cur_v);
        return result;
    }
};

TEST(e0100, e0057) {
    vector<vector<int>> m = str_to_mat<int>("[[1,3],[6,9]]");
    vector<int> v = str_to_vec<int>("[2,5]");
    vector<vector<int>> ans = str_to_mat<int>("[[1,5],[6,9]]");
    ASSERT_THAT(Solution().insert(m, v), ans);
    m = str_to_mat<int>("[[1,2],[3,5],[6,7],[8,10],[12,16]]");
    v = str_to_vec<int>("[4,8]");
    ans = str_to_mat<int>("[[1,2],[3,10],[12,16]]");
    ASSERT_THAT(Solution().insert(m, v), ans);
}
