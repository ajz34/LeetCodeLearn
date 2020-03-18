// https://leetcode-cn.com/problems/rectangle-overlap/

#include "extern.h"

class S0836 {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (rec1[0] > rec2[0]) swap(rec1, rec2);
        if (rec2[1] >= rec1[3] || rec2[3] <= rec1[1]) return false;
        if (rec2[0] >= rec1[2]) return false;
        return true;
    }
};

TEST(e0900, e0836) {
    vector<int> rec1, rec2;
    rec1 = str_to_vec<int>("[0,0,2,2]");
    rec2 = str_to_vec<int>("[1,1,3,3]");
    ASSERT_TRUE(S0836().isRectangleOverlap(rec1, rec2));
    rec1 = str_to_vec<int>("[0,0,1,1]");
    rec2 = str_to_vec<int>("[1,0,2,1]");
    ASSERT_FALSE(S0836().isRectangleOverlap(rec1, rec2));
}
