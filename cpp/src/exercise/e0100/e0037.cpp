// https://leetcode-cn.com/problems/sudoku-solver/

#include "extern.h"

class Solution {
public:
    void find_and_erase(vector<int>& v, int t) {
        if (v.empty()) return;
        auto p = find(v.begin(), v.end(), t);
        if (p != v.end()) v.erase(p);
    }

private:
    void clear_ij(vector<vector<int>>& board, vector<vector<vector<int>>>& stat, int i, int j) {
        int bij = board[i][j];
        if (bij != 0) {
            for (int k = 0; k < 9; ++k) {
                find_and_erase(stat[i][k], bij);
                find_and_erase(stat[k][j], bij);
            }
            for (int k = 0; k < 3; ++k)
                for (int l = 0; l < 3; ++l)
                    find_and_erase(stat[(i / 3) * 3 + k][(j / 3) * 3 + l], bij);
        }
    }

    bool SudokuDFS(vector<vector<int>>& board, vector<vector<vector<int>>>& stat, int unsolved) {
        while (unsolved > 0) {
            bool modified = false;
            for (int i = 0; i < 9; ++i)
                for (int j = 0; j < 9; ++j) {
                    if (board[i][j] > 0) continue;
                    if (stat[i][j].size() == 0) return false;
                    if (stat[i][j].size() == 1) {
                        board[i][j] = stat[i][j][0];
                        modified = true;
                        unsolved -= 1;
                        clear_ij(board, stat, i, j);
                        continue;
                    }
                }
            if (!modified) break;
        }
        if (unsolved == 0) return true;
        int next_i = -1, next_j = -1, min_count = 1;
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] > 0) continue;
                if (stat[i][j].size() > min_count) {
                    min_count = int(stat[i][j].size());
                    next_i = i; next_j = j;
                }
            }
        assert(next_i != -1);
        for (int k = 0; k < stat[next_i][next_j].size(); ++k) {
            vector<vector<int>> next_board{ board };
            vector<vector<vector<int>>> next_stat{ stat };
            next_board[next_i][next_j] = stat[next_i][next_j][k];
            clear_ij(next_board, next_stat, next_i, next_j);
            unsolved -= 1;
            if (SudokuDFS(next_board, next_stat, unsolved)) {
                board = next_board;
                stat = next_stat;
                return true;
            }
            else unsolved += 1;
        }
        return false;
    }

    void solveSudokuInt(vector<vector<int>>& board) {
        // 0. generate board status map
        vector<vector<vector<int>>> stat(9, vector<vector<int>>(9, vector<int>{}));
        // 1. insert vector [1, 2, ..., 9] to blanks
        vector<int> v19 = vector<int>{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int unsolved = 0;
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] == 0) {
                    stat[i][j] = v19;
                    unsolved += 1;
                }
        // 2. clear values
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                clear_ij(board, stat, i, j);
        // 3. solve Sudoku by DFS
        assert(SudokuDFS(board, stat, unsolved));
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> boardint(9, vector<int>(9, 0));
        for (size_t i = 0; i < 9; ++i)
            for (size_t j = 0; j < 9; ++j)
                switch (board[i][j])
                {
                case '.':
                    break;
                default:
                    boardint[i][j] = board[i][j] - '0';
                    break;
                }
        solveSudokuInt(boardint);
        for (size_t i = 0; i < 9; ++i)
            for (size_t j = 0; j < 9; ++j)
                board[i][j] = boardint[i][j] + '0';
        return;
    }
};

TEST(e0100, e0037) {
    auto block = str_to_mat<char>("[ \
        [5, 3, ., ., 7, ., ., ., .], \
        [6, ., ., 1, 9, 5, ., ., .], \
        [., 9, 8, ., ., ., ., 6, .], \
        [8, ., ., ., 6, ., ., ., 3], \
        [4, ., ., 8, ., 3, ., ., 1], \
        [7, ., ., ., 2, ., ., ., 6], \
        [., 6, ., ., ., ., 2, 8, .], \
        [., ., ., 4, 1, 9, ., ., 5], \
        [., ., ., ., 8, ., ., 7, 9]  \
    ]");
    Solution().solveSudoku(block);
    auto ans = str_to_mat<char>("[   \
        [5, 3, 4, 6, 7, 8, 9, 1, 2], \
        [6, 7, 2, 1, 9, 5, 3, 4, 8], \
        [1, 9, 8, 3, 4, 2, 5, 6, 7], \
        [8, 5, 9, 7, 6, 1, 4, 2, 3], \
        [4, 2, 6, 8, 5, 3, 7, 9, 1], \
        [7, 1, 3, 9, 2, 4, 8, 5, 6], \
        [9, 6, 1, 5, 3, 7, 2, 8, 4], \
        [2, 8, 7, 4, 1, 9, 6, 3, 5], \
        [3, 4, 5, 2, 8, 6, 1, 7, 9], \
    ]");
    ASSERT_THAT(block, ans);
}
