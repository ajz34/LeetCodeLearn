// https://leetcode-cn.com/problems/unique-paths-ii/

#include "extern.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // int overflow could occur! use long long instead.
        vector<vector<long long>> grid;
        for (auto row : obstacleGrid) {
            grid.push_back({});
            for (auto col : row) grid.back().push_back(col);
        }
        int row_size = grid.size(); int col_size = grid[0].size();
        if (grid[0][0] == 1) return 0;
        grid[0][0] = 1;
        for (int r = 0; r < row_size; ++r) {
            for (int c = (r == 0 ? 1 : 0); c < col_size; ++c) {
                if (grid[r][c] == 1)
                    grid[r][c] = 0;
                else {
                    if (r > 0) grid[r][c] += grid[r - 1][c];
                    if (c > 0) grid[r][c] += grid[r][c - 1];
                }
            }
        }
        return int(grid[row_size - 1][col_size - 1]);
    }
};

TEST(e0100, e0063) {
    auto mat = str_to_mat<int>("[\
        [0, 0, 0], \
        [0, 1, 0], \
        [0, 0, 0]  \
    ]");
    ASSERT_EQ(Solution().uniquePathsWithObstacles(mat), 2);
}
