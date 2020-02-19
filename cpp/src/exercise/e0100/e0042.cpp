// https://leetcode-cn.com/problems/trapping-rain-water/

#include "extern.h"

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        auto pl = height.cbegin(), pr = prev(height.cend());
        int h = 0, result = 0;
        while (pl - pr <= 0) {
            if (*pl >= h && *pr >= h) {
                h = max(min(*pl, *pr), h);
                if (*pl <= *pr) ++pl;
                else --pr;
            }
            else if (*pl <= h)
                result += h - *(pl++);
            else
                result += h - *(pr--);
        }
        return result;
    }
};

TEST(e0100, e0042) {
    vector<int> v = str_to_vec<int>("[0,1,0,2,1,0,1,3,2,1,2,1]");
    ASSERT_EQ(Solution().trap(v), 6);
}

/* 参考官方题解 https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode/ */
