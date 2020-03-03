// https://leetcode-cn.com/problems/pascals-triangle/

#include "extern.h"

class S0118 {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result{ { 1 }, { 1, 1 } };
        if (numRows <= 2) return { result.cbegin(), result.cbegin() + numRows };
        for (int r = 2; r < numRows; ++r) {
            result.push_back({ 1 });
            auto& vec_prev = result[r - 1];
            auto& vec_cur = result[r];
            for (int i = 0; i < r - 1; ++i)
                vec_cur.push_back(vec_prev[i] + vec_prev[i + 1]);
            vec_cur.push_back(1);
        }
        return result;
    }
};

TEST(e0200, e0118) {
    auto res = S0118().generate(5);
    auto ans = str_to_mat<int>("[[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]");
    ASSERT_THAT(res, ans);
}
