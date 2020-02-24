// https://leetcode-cn.com/problems/set-matrix-zeroes/

#include "extern.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        bool clear_r1 = false, clear_c1 = false;
        int size_r = matrix.size(), size_c = matrix[0].size();
        for (int r = 0; r < size_r; ++r)
            if (matrix[r][0] == 0) { clear_r1 = true; break; }
        for (int c = 0; c < size_c; ++c)
            if (matrix[0][c] == 0) { clear_c1 = true; break; }
        for (int r = 1; r < size_r; ++r)
            for (int c = 1; c < size_c; ++c)
                if (matrix[r][c] == 0)
                    matrix[r][0] = matrix[0][c] = 0;
        for (int r = 1; r < size_r; ++r)
            if (matrix[r][0] == 0)
                for (int c = 1; c < size_c; ++c)
                    matrix[r][c] = 0;
        for (int c = 1; c < size_c; ++c)
            if (matrix[0][c] == 0)
                for (int r = 1; r < size_r; ++r)
                    matrix[r][c] = 0;
        if (clear_c1)
            for (int c = 0; c < size_c; ++c)
                matrix[0][c] = 0;
        if (clear_r1)
            for (int r = 0; r < size_r; ++r)
                matrix[r][0] = 0;
    }
};

TEST(e0100, e0073) {
    vector<vector<int>> mat, ans;
    mat = str_to_mat<int>("[\
        [1, 1, 1], \
        [1, 0, 1], \
        [1, 1, 1]  \
    ]");
    ans = str_to_mat<int>("[\
        [1, 0, 1], \
        [0, 0, 0], \
        [1, 0, 1]  \
    ]");
    Solution().setZeroes(mat);
    ASSERT_THAT(mat, ans);

    mat = str_to_mat<int>("[\
        [0, 1, 2, 0], \
        [3, 4, 5, 2], \
        [1, 3, 1, 5]  \
    ]");
    ans = str_to_mat<int>("[\
        [0, 0, 0, 0], \
        [0, 4, 5, 0], \
        [0, 3, 1, 0]  \
    ]");
    Solution().setZeroes(mat);
    ASSERT_THAT(mat, ans);
}
