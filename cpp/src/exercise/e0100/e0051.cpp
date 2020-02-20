// https://leetcode-cn.com/problems/n-queens/

#include "extern.h"

class Solution {
    void chessNQueens(vector<vector<bool>>& chess, int n, vector<int>& v, vector<vector<int>>& sol) {
        if (n == chess.size()) { sol.push_back(v); return; }
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
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> chess(n, vector<bool>(n, false));
        vector<int> v{}; vector<vector<int>> sol{};
        chessNQueens(chess, 0, v, sol);

        vector<vector<string>> result(sol.size(), vector<string>(n, string(n, '.')));
        for (int s = 0; s < sol.size(); ++s)
            for (int i = 0; i < n; ++i)
                result[s][i][sol[s][i]] = 'Q';
        return result;
    }
};

TEST(e0100, e0051) {
    auto res_mat = Solution().solveNQueens(4);
    auto ans_mat = vector<vector<string>>{ {
        ".Q..",  // Solution 1
        "...Q",
        "Q...",
        "..Q."
        },{
        "..Q.",  // Solution 2
        "Q...",
        "...Q",
        ".Q.." 
    } };
    ASSERT_THAT(res_mat, ans_mat);
}
