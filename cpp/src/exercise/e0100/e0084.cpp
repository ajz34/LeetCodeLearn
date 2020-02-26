// https://leetcode-cn.com/problems/largest-rectangle-in-histogram/

#include "extern.h"

class S0084 {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        map<int, int, greater<int>> mp;
        int max_area = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int h = heights[i];
            if (mp.find(h) == mp.cend()) mp[h] = i;
            auto ph = mp.find(h);
            int erase_cnt = 0;
            for (auto p = mp.cbegin(); p != mp.cend();) {
                if (p->first > h) {
                    max_area = max((i - p->second) * p->first, max_area);
                    ph->second = min(p->second, ph->second);
                    p = mp.erase(p);
                }
                else break;
            }
        }
        for (auto& p : mp)
            max_area = max((int(heights.size()) - p.second) * p.first, max_area);
        return max_area;
    }
};

TEST(e0100, e0084) {
    vector<int> heights;
    heights = str_to_vec<int>("[2,1,5,6,2,3]");
    ASSERT_EQ(S0084().largestRectangleArea(heights), 10);
}
