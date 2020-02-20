// https://leetcode-cn.com/problems/n-queens-ii/

#include "extern.h"

class Solution {
    void chessNQueens(vector<vector<bool>>& chess, int n, vector<int>& v, int& sol) {
        if (n == chess.size()) { ++sol; return; }
        for (int i = 0; i < chess.size(); ++i) {
            if (!chess[n][i]) {
                v.push_back(i);
                auto chessc{ chess };
                for (int j = 0; j < chess.size(); ++j)
                    chessc[n][j] = chessc[j][i] = true;
                int s;
                s = 0; while (n + s < chess.size() && i + s < chess.size()) { chessc[n + s][i + s] = true; ++s; }
                s = 0; while (n + s < chess.size() && i - s >= 0) { chessc[n + s][i - s] = true; ++s; }
                chessNQueens(chessc, n + 1, v, sol);
                v.pop_back();
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<vector<bool>> chess(n, vector<bool>(n, false));
        vector<int> v{}; int sol = 0;
        chessNQueens(chess, 0, v, sol);
        return sol;
    }
};

TEST(e0100, e0052) {
    ASSERT_EQ(Solution().totalNQueens(4), 2);
}
