// https://leetcode-cn.com/problems/merge-intervals/

#include "extern.h"

class Solution {
    struct MergeCompare {
        inline bool operator()(const vector<int>& v1, const vector<int>& v2) const { return v1[0] < v2[0]; }
    };
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), MergeCompare());
        vector<vector<int>> result;
        vector<int> cur_v;
        for (auto& v : intervals) {
            if (cur_v.empty()) cur_v = v;
            if (v[0] <= cur_v[1]) cur_v[1] = max(cur_v[1], v[1]);
            else {
                result.push_back(cur_v);
                cur_v = v;
            }
        }
        if (!cur_v.empty()) result.push_back(cur_v);
        return result;
    }
};

TEST(e0100, e0056) {
    vector<vector<int>> m = str_to_mat<int>("[[1,3],[2,6],[8,10],[15,18]]");
    vector<vector<int>> res = str_to_mat<int>("[[1,6],[8,10],[15,18]]");
    ASSERT_THAT(Solution().merge(m), res);
    m = str_to_mat<int>("[[1,4],[4,5]]");
    res = str_to_mat<int>("[[1,5]]");
    ASSERT_THAT(Solution().merge(m), res);
}
