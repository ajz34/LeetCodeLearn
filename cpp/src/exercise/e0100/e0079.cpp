// https://leetcode-cn.com/problems/word-search/

#include "extern.h"

class Solution {
    vector<vector<char>>* board = nullptr;
    string* word = nullptr;
    vector<vector<bool>>* status = nullptr;
    int r_size = 0, c_size = 0;

    bool wordSearchDFS(int idx, int r, int c) {
        if (idx == word->size()) return true;
        if ((*word)[idx] != (*board)[r][c] || (*status)[r][c]) return false;
        (*status)[r][c] = true;
        if (r > 0 && wordSearchDFS(idx + 1, r - 1, c)) return true;
        if (c > 0 && wordSearchDFS(idx + 1, r, c - 1)) return true;
        if (r < r_size - 1 && wordSearchDFS(idx + 1, r + 1, c)) return true;
        if (c < c_size - 1 && wordSearchDFS(idx + 1, r, c + 1)) return true;
        (*status)[r][c] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        this->board = &board; this->word = &word;
        if (board.empty() || board.front().empty()) return false;
        r_size = board.size(); c_size = board.front().size();
        status = new vector<vector<bool>>(r_size, vector<bool>(c_size, false));

        for (int r = 0; r < r_size; ++r)
            for (int c = 0; c < c_size; ++c)
                if (word.size() == 1 && word[0] == board[r][c]) return true;
                else if (wordSearchDFS(0, r, c)) return true;
        return false;
    }
};

TEST(e0100, e0079) {
    vector<vector<char>> board = vector<vector<char>>{ {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
    ASSERT_TRUE(Solution().exist(board, "ABCCED"));
    ASSERT_TRUE(Solution().exist(board, "SEE"));
    ASSERT_FALSE(Solution().exist(board, "ABCB"));
}
