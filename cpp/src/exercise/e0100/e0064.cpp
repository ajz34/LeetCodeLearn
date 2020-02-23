// https://leetcode-cn.com/problems/minimum-path-sum/

#include "extern.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row_size = grid.size(), col_size = grid[0].size();
        for (int r = 0; r < row_size; ++r) {
            for (int c = 0; c < col_size; ++c) {
                if (r == 0 && c == 0) continue;
                else if (r == 0) grid[r][c] += grid[r][c - 1];
                else if (c == 0) grid[r][c] += grid[r - 1][c];
                else grid[r][c] += min(grid[r][c - 1], grid[r - 1][c]);
            }
        }
        return grid[row_size - 1][col_size - 1];
    }
};

TEST(e0100, e0064) {
    auto mat = str_to_mat<int>("[\
        [1, 3, 1], \
        [1, 5, 1], \
        [4, 2, 1]  \
    ]");
    ASSERT_EQ(Solution().minPathSum(mat), 7);
}
