// https://leetcode-cn.com/problems/maximal-rectangle/

#include "extern.h"

class S0085 {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix.front().empty()) return 0;
        int result = 0;
        int r_size = matrix.size(), c_size = matrix.front().size();
        vector<vector<int>> stat(r_size, vector<int>(c_size, 0));
        for (int r = 0; r < r_size; ++r) {
            for (int c = 0; c < c_size; ++c) {
                if (matrix[r][c] == '1') {
                    if (c == 0) stat[r][c] = 1;
                    else stat[r][c] = stat[r][c - 1] + 1;
                }
                result = max(stat[r][c], result);
                bool fill_zero = (stat[r][c] == 0);
                for (int ri = r - 1; ri >= 0; --ri) {
                    if (fill_zero)
                        if (stat[ri][c] != 0) stat[ri][c] = 0;
                        else break;
                    if (stat[ri][c] == 0) { fill_zero = true; continue; }
                    if (c == 0) stat[ri][c] = r - ri + 1;
                    else stat[ri][c] = stat[ri][c - 1] + r - ri + 1;
                    result = max(stat[ri][c], result);
                }
            }
        }
        return result;
    }
};

TEST(e0100, e0085) {
    vector<vector<char>> matrix;
    matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    ASSERT_EQ(S0085().maximalRectangle(matrix), 6);
}
