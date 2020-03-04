// https://leetcode-cn.com/problems/rotting-oranges/

#include "extern.h"

class S0994 {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid.front().empty()) return 0;
        int r_size = grid.size(), c_size = grid.front().size();
        int cnt_1 = 0;
        vector<pair<int, int>> vec_1, vec_2;
        for (int r = 0; r < r_size; ++r) {
            for (int c = 0; c < c_size; ++c) {
                switch (grid[r][c])
                {
                case 1:
                    cnt_1++;
                    break;
                case 2:
                    vec_2.push_back(make_pair(r, c));
                    break;
                default:
                    break;
                }
            }
        }
        int mod_1 = 0, mod_times = 0;
        auto add_1 = [&mod_1, &vec_1, &vec_2, &r_size, &c_size, &grid](int r, int c) {
            if (r < 0 || r >= r_size || c < 0 || c >= c_size) return;
            if (grid[r][c] != 1) return;
            vec_1.push_back(make_pair(r, c));
            grid[r][c] = 2;
            mod_1 += 1;
        };
        while (!vec_2.empty()) {
            vec_1.clear();
            int r, c;
            for (auto& p : vec_2) {
                r = p.first, c = p.second;
                add_1(r - 1, c);
                add_1(r + 1, c);
                add_1(r, c - 1);
                add_1(r, c + 1);
            }
            if (vec_1.empty()) break;
            mod_times += 1;
            swap(vec_1, vec_2);
        }
        if (mod_1 != cnt_1) return -1;
        else return mod_times;
    }
};

TEST(e1000, e0994) {
    vector<vector<int>> grid;
    grid = str_to_mat<int>("[[2,1,1],[1,1,0],[0,1,1]]");
    ASSERT_EQ(S0994().orangesRotting(grid), 4);
    grid = str_to_mat<int>("[[2,1,1],[0,1,1],[1,0,1]]");
    ASSERT_EQ(S0994().orangesRotting(grid), -1);
    grid = str_to_mat<int>("[[0,2]]");
    ASSERT_EQ(S0994().orangesRotting(grid), 0);
}
