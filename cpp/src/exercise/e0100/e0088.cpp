// https://leetcode-cn.com/problems/merge-sorted-array/

#include "extern.h"

class S0088 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1 = m - 1, i2 = n - 1, ip = m + n - 1;
        while (i1 >= 0 && i2 >= 0) {
            if (nums1[i1] >= nums2[i2]) nums1[ip--] = nums1[i1--];
            else nums1[ip--] = nums2[i2--];
        }
        while (i1 >= 0) nums1[ip--] = nums1[i1--];
        while (i2 >= 0) nums1[ip--] = nums2[i2--];
    }
};

TEST(e0100, e0088) {
    vector<int> nums1, nums2, ans;
    nums1 = str_to_vec<int>("[1,2,3,0,0,0]");
    nums2 = str_to_vec<int>("[2,5,6]");
    ans = str_to_vec<int>("[1,2,2,3,5,6]");
    S0088().merge(nums1, 3, nums2, 3);
    ASSERT_THAT(nums1, ans);
}
