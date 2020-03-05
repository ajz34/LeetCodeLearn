// https://leetcode-cn.com/problems/surrounded-regions/

#include "extern.h"

class S0130 {
    void solveInner(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board.front().size()) return;
        if (board[r][c] == 'O') {
            board[r][c] = 'C';
            solveInner(board, r - 1, c);
            solveInner(board, r + 1, c);
            solveInner(board, r, c - 1);
            solveInner(board, r, c + 1);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board.front().empty()) return;
        for (int r = 0; r < board.size(); ++r) {
            solveInner(board, r, 0);
            solveInner(board, r, board.front().size() - 1);
        }
        for (int c = 0; c < board.front().size(); ++c) {
            solveInner(board, 0, c);
            solveInner(board, board.size() - 1, c);
        }
        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board.front().size(); ++c) {
                switch (board[r][c]) {
                case 'O':
                    board[r][c] = 'X';
                    break;
                case 'C':
                    board[r][c] = 'O';
                    break;
                default:
                    break;
                }
            }
        }
    }
};

TEST(e0200, e0130) {
    vector<vector<char>> board{ {'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'} };
    vector<vector<char>> ans{ {'X','X','X','X'},{'X','X','X','X'},{'X','X','X','X'},{'X','O','X','X'} };
    S0130().solve(board);
    ASSERT_THAT(board, ans);
}
