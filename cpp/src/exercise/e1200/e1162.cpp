// https://leetcode-cn.com/problems/as-far-from-land-as-possible/

#include "extern.h"

class S1162 {
    struct Coord {
        int row = -1;
        int col = -1;
        Coord(int r, int c) : row(r), col(c) {}
    };
public:
    int maxDistance(vector<vector<int>>& grid) {
        int r_size = grid.size(), c_size = grid.front().size();
        if (r_size * c_size == 1) return -1;

        auto check_coord = [&grid, &r_size, &c_size](int r, int c) {
            return !(r < 0 || r >= r_size || c < 0 || c >= c_size);
        };
        auto check_nearest = [&grid, &r_size, &c_size](int r, int c) {
            if (grid[r][c] == 0) return false;
            if ((r > 0 && grid[r - 1][c] == 0) ||
                (r < r_size - 1 && grid[r + 1][c] == 0) ||
                (c > 0 && grid[r][c - 1] == 0) ||
                (c < c_size - 1 && grid[r][c + 1] == 0)) return true;
            return false;
        };

        vector<Coord> bfs_prev, bfs_next;
        for (int r = 0; r < r_size; ++r)
            for (int c = 0; c < c_size; ++c)
                if (check_nearest(r, c)) bfs_prev.push_back({ r, c });
        if (bfs_prev.size() == 0 || bfs_prev.size() == r_size * c_size) return -1;

        int result = 0;
        while (!bfs_prev.empty()) {
            bfs_next.clear();
            result += 1;
            for (auto& crd : bfs_prev) {
                int r = crd.row, c = crd.col;
                if (r > 0 && grid[r - 1][c] == 0) { bfs_next.push_back({ r - 1, c }); grid[r - 1][c] = 1; }
                if (r < r_size - 1 && grid[r + 1][c] == 0) { bfs_next.push_back({ r + 1, c }); grid[r + 1][c] = 1; }
                if (c > 0 && grid[r][c - 1] == 0) { bfs_next.push_back({ r, c - 1 }); grid[r][c - 1] = 1; }
                if (c < c_size - 1 && grid[r][c + 1] == 0) { bfs_next.push_back({ r, c + 1 }); grid[r][c + 1] = 1; }
            }
            swap(bfs_prev, bfs_next);
        }
        return result - 1;
    }
};

TEST(e1200, e1162) {
    vector<vector<int>> grid;
    grid = str_to_mat<int>("[[1,0,1],[0,0,0],[1,0,1]]");
    ASSERT_EQ(S1162().maxDistance(grid), 2);
    grid = str_to_mat<int>("[[1,0,0],[0,0,0],[0,0,0]]");
    ASSERT_EQ(S1162().maxDistance(grid), 4);
}
