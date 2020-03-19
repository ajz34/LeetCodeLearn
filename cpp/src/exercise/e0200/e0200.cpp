// https://leetcode-cn.com/problems/number-of-islands/

#include "extern.h"

class S0200 {
    void paint(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid.front().size()) return;
        if (grid[x][y] == '1') {
            grid[x][y] = '2';
            paint(grid, x + 1, y);
            paint(grid, x - 1, y);
            paint(grid, x, y + 1);
            paint(grid, x, y - 1);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid.front().empty()) return 0;
        int result = 0;
        for (int x = 0; x < grid.size(); ++x) {
            for (int y = 0; y < grid.front().size(); ++y) {
                if (grid[x][y] == '1') {
                    result += 1;
                    paint(grid, x, y);
                }
            }
        }
        return result;
    }
};

TEST(e0200, e0200) {
    vector<vector<char>> grid;
    grid = {
        { '1','1','1','1','0' },
        { '1','1','0','1','0' },
        { '1','1','0','0','0' },
        { '0','0','0','0','0' },
    };
    ASSERT_EQ(S0200().numIslands(grid), 1);
    grid = {
        { '1','1','0','0','0' },
        { '1','1','0','0','0' },
        { '0','0','1','0','0' },
        { '0','0','0','1','1' },
    };
    ASSERT_EQ(S0200().numIslands(grid), 3);
}
