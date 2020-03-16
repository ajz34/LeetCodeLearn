// https://leetcode-cn.com/problems/dungeon-game/

#include "extern.h"

class S0174 {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r_size = dungeon.size(), c_size = dungeon.front().size();
        vector<int> dp(c_size, 0);
        dp[c_size - 1] = max(-dungeon[r_size - 1][c_size - 1], 0);
        for (int c = c_size - 1; c-- > 0;)
            dp[c] = max(dp[c + 1] - dungeon[r_size - 1][c], 0);
        for (int r = r_size - 1; r-- > 0;) {
            dp[c_size - 1] = max(dp[c_size - 1] - dungeon[r][c_size - 1], 0);
            for (int c = c_size - 1; c-- > 0;) {
                dp[c] = min(dp[c] - dungeon[r][c], dp[c + 1] - dungeon[r][c]);
                dp[c] = max(dp[c], 0);
            }
        }
        return dp[0] + 1;
    }
};

TEST(e0200, e0174) {
    vector<vector<int>> dungeon;
    dungeon = str_to_mat<int>("[[-2,-3,3],[-5,-10,1],[10,30,-5]]");
    ASSERT_EQ(S0174().calculateMinimumHP(dungeon), 7);
}
