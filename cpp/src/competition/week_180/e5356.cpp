// https://leetcode-cn.com/problems/lucky-numbers-in-a-matrix/

#include "extern.h"

class S5356 {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int INF = 10000000;
        if (matrix.empty() && matrix.front().empty()) return {};
        int r_size = matrix.size(), c_size = matrix.front().size();
        vector<int> row_min(r_size, -1), col_max(c_size, -1);
        for (int r = 0; r < r_size; ++r) {
            int min_val = INF;
            for (int c = 0; c < c_size; ++c) {
                if (matrix[r][c] < min_val) {
                    min_val = matrix[r][c];
                    row_min[r] = c;
                }
            }
        }
        for (int c = 0; c < c_size; ++c) {
            int max_val = -INF;
            for (int r = 0; r < r_size; ++r) {
                if (matrix[r][c] > max_val) {
                    max_val = matrix[r][c];
                    col_max[c] = r;
                }
            }
        }
        vector<int> result;
        for (int r = 0; r < r_size; ++r) {
            if (col_max[row_min[r]] == r)
                result.push_back(matrix[r][row_min[r]]);
        }
        return result;
    }
};

TEST(week180, e5356) {
    vector<vector<int>> matrix; vector<int> ans;
    matrix = str_to_mat<int>("[[3,7,8],[9,11,13],[15,16,17]]");
    ans = str_to_vec<int>("[15]");
    ASSERT_THAT(vec_to_set(S5356().luckyNumbers(matrix)), vec_to_set(ans));
    matrix = str_to_mat<int>("[[1,10,4,2],[9,3,8,7],[15,16,17,12]]");
    ans = str_to_vec<int>("[12]");
    ASSERT_THAT(vec_to_set(S5356().luckyNumbers(matrix)), vec_to_set(ans));
    matrix = str_to_mat<int>("[[7,8],[1,2]]");
    ans = str_to_vec<int>("[7]");
    ASSERT_THAT(vec_to_set(S5356().luckyNumbers(matrix)), vec_to_set(ans));
}
