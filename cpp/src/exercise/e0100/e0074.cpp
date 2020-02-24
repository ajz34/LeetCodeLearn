// https://leetcode-cn.com/problems/search-a-2d-matrix/

#include "extern.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        vector<int> col_first;
        for (auto& row : matrix) col_first.push_back(row[0]);
        auto pcf = upper_bound(col_first.cbegin(), col_first.cend(), target);
        if (pcf == col_first.cbegin()) return false;
        --pcf;

        auto& row_target = matrix[pcf - col_first.cbegin()];
        auto p = lower_bound(row_target.cbegin(), row_target.cend(), target);
        return (p != row_target.cend()) && (*p == target);
    }
};

TEST(e0100, e0074) {
    vector<vector<int>> mat;
    mat = str_to_mat<int>("[\
        [1,  3,   5,  7], \
        [10, 11, 16, 20], \
        [23, 30, 34, 50]  \
    ]");
    ASSERT_TRUE(Solution().searchMatrix(mat, 3));
    ASSERT_FALSE(Solution().searchMatrix(mat, 13));
}
