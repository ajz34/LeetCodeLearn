// https://leetcode-cn.com/problems/available-captures-for-rook/

#include "extern.h"

class S0999 {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int r_size = board.size(), c_size = board.front().size();
        int rR = -1, cR = -1;
        for (int r = 0; r < r_size; ++r)
            for (int c = 0; c < c_size; ++c)
                if (board[r][c] == 'R') { rR = r, cR = c; break; }
        int result = 0;
        auto update_stat = [&board, &result](int r, int c) {
            if (board[r][c] == 'p') { ++result; cout << r << " " << c << endl; return true; }
            else if (board[r][c] == 'B') return true;
            return false;
        };
        for (int r = rR; r-- > 0;) if (update_stat(r, cR)) break;
        for (int r = rR + 1; r < r_size; ++r) if (update_stat(r, cR)) break;
        for (int c = cR; c-- > 0;) if (update_stat(rR, c)) break;
        for (int c = cR + 1; c < c_size; ++c) if (update_stat(rR, c)) break;
        return result;
    }
};

TEST(e1000, e0999) {
    vector<vector<char>> board;
    board = { {'.','.','.','.','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'.','.','.','R','.','.','.','p'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'} };
    ASSERT_EQ(S0999().numRookCaptures(board), 3);
    board = { {'.','.','.','.','.','.','.','.'},{'.','p','p','p','p','p','.','.'},{'.','p','p','B','p','p','.','.'},{'.','p','B','R','B','p','.','.'},{'.','p','p','B','p','p','.','.'},{'.','p','p','p','p','p','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'} };
    ASSERT_EQ(S0999().numRookCaptures(board), 0);
    board = { {'.','.','.','.','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'p','p','.','R','.','p','B','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','B','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'.','.','.','.','.','.','.','.'} };
    ASSERT_EQ(S0999().numRookCaptures(board), 3);
}
