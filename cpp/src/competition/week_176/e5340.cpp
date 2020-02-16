// https://leetcode-cn.com/problems/count-negative-numbers-in-a-sorted-matrix/

#include "extern.h"

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int result = 0;
        for (auto row = grid.crbegin(); row != grid.crend(); ++row) {
            if (row->back() >= 0) break;
            for (auto val = row->crbegin(); val != row->crend(); ++val) {
                if (*val < 0) result += 1;
                else break;
            }
        }
        return result;
    }

    int countNegatives_slow(vector<vector<int>>& grid) {
        int result = 0;
        for (auto row : grid)
            for (auto val : row)
                if (val < 0) result += 1;
        return result;
    }
};

TEST(week176, e5340) {
    auto grid = str_to_mat<int>("[[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]");
    ASSERT_EQ(Solution().countNegatives(grid), 8);
    grid = str_to_mat<int>("[[3,2],[1,0]]");
    ASSERT_EQ(Solution().countNegatives(grid), 0);
    grid = str_to_mat<int>("[[1,-1],[-1,-1]]");
    ASSERT_EQ(Solution().countNegatives(grid), 3);
    grid = str_to_mat<int>("[[-1]]");
    ASSERT_EQ(Solution().countNegatives(grid), 1);
}
