// https://leetcode-cn.com/problems/max-area-of-island/

#include "extern.h"

class S0695 {
    int maxAreaOfIslandInner(vector<vector<int>>& grid, int r0, int c0) {
        int r_size = grid.size(), c_size = grid.front().size();
        vector<pair<int, int>> vec_prev{ { r0, c0 } }, vec_next;
        int result = 0;
        while (!vec_prev.empty()) {
            vec_next.clear();
            for (auto& p : vec_prev) {
                int r = p.first, c = p.second;
                if (grid[r][c] == 1) {
                    grid[r][c] = 0; result += 1;
                    if (r > 0)          vec_next.push_back({ r - 1, c });
                    if (r < r_size - 1) vec_next.push_back({ r + 1, c });
                    if (c > 0)          vec_next.push_back({ r, c - 1 });
                    if (c < c_size - 1) vec_next.push_back({ r, c + 1 });
                }
            }
            swap(vec_prev, vec_next);
        }
        return result;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid.front().empty()) return 0;
        int r_size = grid.size(), c_size = grid.front().size();
        int result = 0;
        for (int r = 0; r < r_size; ++r) {
            for (int c = 0; c < c_size; ++c) {
                if (grid[r][c] == 1)
                    result = max(maxAreaOfIslandInner(grid, r, c), result);
            }
        }
        return result;
    }
};

TEST(e0700, e0695) {
    vector<vector<int>> grid;
    grid = str_to_mat<int>("\
        [[0,0,1,0,0,0,0,1,0,0,0,0,0],\
         [0,0,0,0,0,0,0,1,1,1,0,0,0],\
         [0,1,1,0,1,0,0,0,0,0,0,0,0],\
         [0,1,0,0,1,1,0,0,1,0,1,0,0],\
         [0,1,0,0,1,1,0,0,1,1,1,0,0],\
         [0,0,0,0,0,0,0,0,0,0,1,0,0],\
         [0,0,0,0,0,0,0,1,1,1,0,0,0],\
         [0,0,0,0,0,0,0,1,1,0,0,0,0]]\
    ");
    ASSERT_EQ(S0695().maxAreaOfIsland(grid), 6);
    grid = str_to_mat<int>("[[0,0,0,0,0,0,0,0]]");
    ASSERT_EQ(S0695().maxAreaOfIsland(grid), 0);
}
