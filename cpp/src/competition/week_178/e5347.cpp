// https://leetcode-cn.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/

#include "extern.h"

class S5347 {
public:
    int minCost(vector<vector<int>>& grid) {
        const int INFTY = 1000000;
        if (grid.empty() || grid.front().empty()) return 0;
        int r_size = grid.size(), c_size = grid.front().size();
        vector<int> r_step{ INFTY, 0, 0, 1, -1 };
        vector<int> c_step{ INFTY, 1, -1, 0, 0 };

        vector<vector<int>> grid_cost(r_size, vector<int>(c_size, INFTY));
        unordered_set<int> cost_next, cost_cur;

        cost_cur.insert(0);
        int cost = 0;
        while (!cost_cur.empty()) {
            cost_next.clear();
            for (int coord : cost_cur) {
                int r = coord / c_size, c = coord % c_size;
                while (true) {
                    if (r < 0 || r >= r_size || c < 0 || c >= c_size) break;
                    if (grid_cost[r][c] <= cost) break;
                    grid_cost[r][c] = cost;
                    if (r == r_size - 1 && c == c_size - 1) return cost;
                    if (r > 0 && grid_cost[r - 1][c] > cost) cost_next.insert((r - 1) * c_size + c);
                    if (r < r_size - 1 && grid_cost[r + 1][c] > cost) cost_next.insert((r + 1) * c_size + c);
                    if (c > 0 && grid_cost[r][c - 1] > cost) cost_next.insert(r * c_size + c - 1);
                    if (c < c_size - 1 && grid_cost[r][c + 1] > cost) cost_next.insert(r * c_size + c + 1);
                    int r_next = r + r_step[grid[r][c]];
                    int c_next = c + c_step[grid[r][c]];
                    r = r_next, c = c_next;
                }
            }
            swap(cost_cur, cost_next);
            cost += 1;
        }
        assert(false);
        return 0;
    }
};

TEST(week178, e5347) {
    vector<vector<int>> grid;
    grid = str_to_mat<int>("[[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]");
    ASSERT_EQ(S5347().minCost(grid), 3);
    grid = str_to_mat<int>("[[1,1,3],[3,2,2],[1,1,4]]");
    ASSERT_EQ(S5347().minCost(grid), 0);
    grid = str_to_mat<int>("[[1,2],[4,3]]");
    ASSERT_EQ(S5347().minCost(grid), 1);
    grid = str_to_mat<int>("[[2,2,2],[2,2,2]]");
    ASSERT_EQ(S5347().minCost(grid), 3);
    grid = str_to_mat<int>("[[4]]");
    ASSERT_EQ(S5347().minCost(grid), 0);
}

/* Ã‚Ω‚£∫
   https://leetcode-cn.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/solution/sui-cost-zeng-da-de-bian-li-tu-shi-jie-fa-by-ajz34/
*/
