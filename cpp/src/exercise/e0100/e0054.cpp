#include "extern.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int row_num = matrix.size(), col_num = matrix[0].size();
        vector<int> result; result.reserve(row_num * col_num);
        vector<vector<bool>> parsed(row_num, vector<bool>(col_num, false));
        vector<int> row_id{ 0, 1, 0, -1 };
        vector<int> col_id{ 1, 0, -1, 0 };
        int pattern = 0;
        int r = 0, c = 0;
        for (int count = 0; count < row_num * col_num; ++count) {
            result.push_back(matrix[r][c]);
            parsed[r][c] = true;
            int rt = r + row_id[pattern], ct = c + col_id[pattern];
            if (rt >= row_num || rt < 0 || ct >= col_num || ct < 0 || parsed[rt][ct])
                pattern = (pattern + 1) % 4;
            r += row_id[pattern]; c += col_id[pattern];
        }
        return result;
    }
};

TEST(e0100, e0054) {
    vector<vector<int>> m = str_to_mat<int>("[\
        [1, 2, 3], \
        [4, 5, 6], \
        [7, 8, 9]  \
    ]");
    vector<int> ans = str_to_vec<int>("[1,2,3,6,9,8,7,4,5]");
    ASSERT_THAT(Solution().spiralOrder(m), ans);
    m = str_to_mat<int>("[\
        [1, 2, 3, 4],   \
        [5, 6, 7, 8],   \
        [9, 10, 11, 12] \
    ]");
    ans = str_to_vec<int>("[1,2,3,4,8,12,11,10,9,5,6,7]");
    ASSERT_THAT(Solution().spiralOrder(m), ans);
}
