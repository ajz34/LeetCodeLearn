// https://leetcode-cn.com/problems/maximum-product-subarray/

#include "extern.h"

class S0152 {
    int maxProductInner(vector<int>& nums, int l, int r) {
        if (r == l) return 0;
        if (r - l == 1) return nums[l];

        int ml = -1, mr = -1, mc = 0;
        for (int i = l; i < r; ++i) {
            if (nums[i] < 0) {
                if (ml == -1) ml = i;
                else mr = i;
                mc += 1;
            }
        }
        if (mc % 2 == 0) {
            int prod = 1;
            for (int i = l; i < r; ++i)
                prod *= nums[i];
            return prod;
        }
        else if (mr == -1) {
            int prod1 = 1, prod2 = 1;
            for (int i = l; i < ml; ++i) prod1 *= nums[i];
            for (int i = ml + 1; i < r; ++i) prod2 *= nums[i];
            return max(prod1, prod2);
        }
        else {
            int prod1 = 1, prod2 = 1, prod3 = 1;
            for (int i = l; i < ml; ++i) prod1 *= nums[i];
            for (int i = ml + 1; i < mr; ++i) prod2 *= nums[i];
            for (int i = mr + 1; i < r; ++i) prod3 *= nums[i];
            return max(prod1 * nums[ml] * prod2, prod2 * nums[mr] * prod3);
        }
    }
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int s = 0, result = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                result = max(maxProductInner(nums, s, i), result);
                s = i + 1;
                result = max(0, result);
            }
        }
        result = max(maxProductInner(nums, s, nums.size()), result);
        return result;
    }
};

TEST(e0200, e0152) {
    vector<int> nums;
    nums = str_to_vec<int>("[2,3,-2,4]");
    ASSERT_EQ(S0152().maxProduct(nums), 6);
    nums = str_to_vec<int>("[-2,0,-1]");
    ASSERT_EQ(S0152().maxProduct(nums), 0);
}
