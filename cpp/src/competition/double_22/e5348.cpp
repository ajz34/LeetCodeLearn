// https://leetcode-cn.com/problems/find-the-distance-value-between-two-arrays/

#include "extern.h"

class S5348 {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int result = 0;
        for (auto v1 : arr1) {
            bool access = true;
            for (auto v2 : arr2) {
                if (abs(v1 - v2) <= d) {
                    access = false;
                    break;
                }
            }
            if (access) result += 1;
        }
        return result;
    }
};

TEST(double22, e5348) {
    vector<int> arr1, arr2;
    arr1 = str_to_vec<int>("[4,5,8]");
    arr2 = str_to_vec<int>("[10,9,1,8]");
    ASSERT_EQ(S5348().findTheDistanceValue(arr1, arr2, 2), 2);
    arr1 = str_to_vec<int>("[1,4,2,3]");
    arr2 = str_to_vec<int>("[-4,-3,6,10,20,30]");
    ASSERT_EQ(S5348().findTheDistanceValue(arr1, arr2, 3), 2);
    arr1 = str_to_vec<int>("[2,1,100,3]");
    arr2 = str_to_vec<int>("[-5,-2,10,-3,7]");
    ASSERT_EQ(S5348().findTheDistanceValue(arr1, arr2, 6), 1);
}
