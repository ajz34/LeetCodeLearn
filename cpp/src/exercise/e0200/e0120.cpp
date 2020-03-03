// https://leetcode-cn.com/problems/triangle/

#include "extern.h"

class S0120 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0) triangle[i][j] += triangle[i - 1][j];
                else if (j == triangle[i].size() - 1) triangle[i][j] += triangle[i - 1][j - 1];
                else triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
            }
        }
        return *min_element(triangle.back().cbegin(), triangle.back().cend());
    }
};

TEST(e0200, e0120) {
    auto triangle = str_to_mat<int>("[[2],[3,4],[6,5,7],[4,1,8,3]]");
    ASSERT_EQ(S0120().minimumTotal(triangle), 11);
}
