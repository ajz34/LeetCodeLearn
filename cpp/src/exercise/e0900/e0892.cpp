// https://leetcode-cn.com/problems/surface-area-of-3d-shapes/

#include "extern.h"

class S0892 {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        if (grid.empty() || grid.front().empty()) return 0;
        int r_size = grid.size(), c_size = grid.front().size();
        int result = 0;
        for (int r = 0; r < r_size; ++r) {
            for (int c = 0; c < c_size; ++c) {
                result += (grid[r][c] == 0) ? 0 : 4 * grid[r][c] + 2;
                if (r > 0) result -= 2 * min(grid[r][c], grid[r - 1][c]);
                if (c > 0) result -= 2 * min(grid[r][c], grid[r][c - 1]);
            }
        }
        return result;
    }
};

TEST(e0900, e0892) {
    vector<vector<int>> grid;
    grid = str_to_mat<int>("[[2]]");
    ASSERT_EQ(S0892().surfaceArea(grid), 10);
    grid = str_to_mat<int>("[[1,2],[3,4]]");
    ASSERT_EQ(S0892().surfaceArea(grid), 34);
    grid = str_to_mat<int>("[[1,0],[0,2]]");
    ASSERT_EQ(S0892().surfaceArea(grid), 16);
    grid = str_to_mat<int>("[[1,1,1],[1,0,1],[1,1,1]]");
    ASSERT_EQ(S0892().surfaceArea(grid), 32);
    grid = str_to_mat<int>("[[2,2,2],[2,1,2],[2,2,2]]");
    ASSERT_EQ(S0892().surfaceArea(grid), 46);
}
