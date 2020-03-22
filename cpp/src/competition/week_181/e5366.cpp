// https://leetcode-cn.com/problems/check-if-there-is-a-valid-path-in-a-grid/

#include "extern.h"

class S5366 {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int r_size = grid.size(), c_size = grid.front().size();
        vector<set<int>> ore{ { 0, 1 }, { 2, 3 }, { 1, 2 }, { 0, 2 }, { 1, 3 }, { 0, 3 } };
        vector<int> prohibit{ 1, 0, 3, 2 };
        vector<pair<int, int>> next_coord{ {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        auto next_step = [&grid, &ore, &prohibit, &r_size, &c_size, &next_coord](int r, int c, int o) {
            while (true) {
                if (r >= r_size || r < 0 || c >= c_size || c < 0) break;
                int p = prohibit[o]; int g = grid[r][c] - 1;
                if (ore[g].find(p) == ore[g].end()) break;
                if (r == r_size - 1 && c == c_size - 1) return true;
                o = (*ore[g].begin() != p ? *ore[g].begin() : *prev(ore[g].end()));
                r += next_coord[o].second;
                c += next_coord[o].first;
            }
            return false;
        };
        return (next_step(0, 0, 0) || next_step(0, 0, 1) || next_step(0, 0, 2) || next_step(0, 0, 3));
    }
};

TEST(week181, e5366) {
    vector<vector<int>> grid;
    grid = str_to_mat<int>("[[2,4,3],[6,5,2]]");
    ASSERT_TRUE(S5366().hasValidPath(grid));
    grid = str_to_mat<int>("[[1,2,1],[1,2,1]]");
    ASSERT_FALSE(S5366().hasValidPath(grid));
    grid = str_to_mat<int>("[[1,1,2]]");
    ASSERT_FALSE(S5366().hasValidPath(grid));
    grid = str_to_mat<int>("[[1,1,1,1,1,1,3]]");
    ASSERT_TRUE(S5366().hasValidPath(grid));
    grid = str_to_mat<int>("[[2],[2],[2],[2],[2],[2],[6]]");
    ASSERT_TRUE(S5366().hasValidPath(grid));
}
