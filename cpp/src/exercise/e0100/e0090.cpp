#include "extern.h"

class S0090 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result{ {} };
        int p = 0, cnt_p = 0, cnt_r = 0;
        while (p < nums.size()) {
            cnt_p = 0;
            while (p + cnt_p < nums.size() && nums[p + cnt_p] == nums[p]) ++cnt_p;
            cnt_r = result.size();
            for (int ir = 0; ir < cnt_r; ++ir) {
                for (int ip = 1; ip <= cnt_p; ++ip) {
                    result.push_back(result[ir]);
                    auto& vr = result[result.size() - 1];
                    for (int ipi = 0; ipi < ip; ++ipi) vr.push_back(nums[p]);
                }
            }
            p += cnt_p;
        }
        return result;
    }
};

TEST(e0100, e0090) {
    vector<int> nums;
    vector<vector<int>> res_mat, ans_mat;
    set<vector<int>> res, ans;
    nums = str_to_vec<int>("[1,2,2]");
    res_mat = S0090().subsetsWithDup(nums);
    ans_mat = str_to_mat<int>("[[],[1],[1,2],[1,2,2],[2],[2,2]]");
    res = set<vector<int>>(res_mat.begin(), res_mat.end());
    ans = set<vector<int>>(ans_mat.begin(), ans_mat.end());
    ASSERT_THAT(res, ans);
}
