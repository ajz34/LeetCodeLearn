// https://leetcode-cn.com/problems/rotate-image/

#include "extern.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        size_t s = matrix.size();
        size_t i_upper, j_upper;
        if (s % 2 == 0) { i_upper = j_upper = s / 2; }
        else { i_upper = (s + 1) / 2; j_upper = (s - 1) / 2; }
        for (size_t i = 0; i < i_upper; ++i)
            for (size_t j = 0; j < j_upper; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[s - 1 - j][i];
                matrix[s - 1 - j][i] = matrix[s - 1 - i][s - 1 - j];
                matrix[s - 1 - i][s - 1 - j] = matrix[j][s - 1 - i];
                matrix[j][s - 1 - i] = t;
            }
    }
};

TEST(e0100, e0048) {
    auto m = str_to_mat<int>("[\
        [1, 2, 3], \
        [4, 5, 6], \
        [7, 8, 9]  \
    ]");
    auto ans = str_to_mat<int>("[\
        [7, 4, 1], \
        [8, 5, 2], \
        [9, 6, 3]  \
    ]");
    Solution().rotate(m);
    ASSERT_THAT(m, ans);
}
