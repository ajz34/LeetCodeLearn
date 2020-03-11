// https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum/

#include "extern.h"

class S1013 {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int r = accumulate(A.begin(), A.end(), 0);
        if (r % 3 != 0) return false;
        r /= 3;
        int v = 0, s = 0;
        for (auto i : A) {
            s += i;
            if (s == r) {
                v += 1;
                s = 0;
                if (v >= 3) return true;
            }
        }
        return false;
    }
};

TEST(e1100, e1013) {
    vector<int> vec;
    vec = str_to_vec<int>("[0,2,1,-6,6,-7,9,1,2,0,1]");
    ASSERT_TRUE(S1013().canThreePartsEqualSum(vec));
    vec = str_to_vec<int>("[0,2,1,-6,6,7,9,-1,2,0,1]");
    ASSERT_FALSE(S1013().canThreePartsEqualSum(vec));
    vec = str_to_vec<int>("[3,3,6,5,-2,2,5,1,-9,4]");
    ASSERT_TRUE(S1013().canThreePartsEqualSum(vec));
}
