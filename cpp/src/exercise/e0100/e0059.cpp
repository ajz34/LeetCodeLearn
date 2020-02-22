// https://leetcode-cn.com/problems/spiral-matrix-ii/

#include "extern.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> row_id{ 0, 1, 0, -1 };
        vector<int> col_id{ 1, 0, -1, 0 };
        vector<vector<int>> result(n, vector<int>(n, 0));
        int p = 0, v = 1, r = 0, c = 0;
        while (v <= n * n) {
            result[r][c] = v; ++v;
            if (r + row_id[p] >= n || r + row_id[p] < 0 || c + col_id[p] >= n || c + col_id[p] < 0 || result[r + row_id[p]][c + col_id[p]] != 0)
                p = (p + 1) % 4;
            r += row_id[p]; c += col_id[p];
        }
        return result;
    }
};

TEST(e0100, e0059) {
    auto ans = str_to_mat<int>("[\
        [1, 2, 3], \
        [8, 9, 4], \
        [7, 6, 5]  \
    ]");
    ASSERT_THAT(Solution().generateMatrix(3), ans);
}
