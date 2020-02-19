#include "extern.h"

class Solution {
public:
    bool isValidBlock(const vector<char>& block) {
        static vector<int> v(11, 0);
        fill(v.begin(), v.end(), 0);
        for (char c : block) {
            switch (c)
            {
            case '.':
                break;
            default:
                v[c - '0'] += 1;
                if (v[c - '0'] > 1) return false;
                break;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<char> v; v.reserve(9);
        // row validation
        for (auto vr : board)
            if (!isValidBlock(vr)) return false;
        // column validation
        for (size_t i = 0; i < 9; ++i) {
            v.clear();
            for (size_t j = 0; j < 9; ++j) v.push_back(board[j][i]);
            if (!isValidBlock(v)) return false;
        }
        // block validation
        for (size_t i = 0; i < 3; ++i) {
            for (size_t j = 0; j < 3; ++j) {
                v.clear();
                for (size_t k = 0; k < 3; ++k)
                    for (size_t l = 0; l < 3; ++l)
                        v.push_back(board[3 * i + k][3 * j + l]);
                if (!isValidBlock(v)) return false;
            }
        }
        return true;
    }
};

TEST(e0100, e0036) {
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
    ASSERT_TRUE(Solution().isValidSudoku(block));
    block[0][0] = '8';
    ASSERT_FALSE(Solution().isValidSudoku(block));
}
