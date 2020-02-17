// https://leetcode-cn.com/problems/next-permutation/

#include "extern.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        // Assert nums.size() > 2
        for (size_t i = nums.size() - 1; i-- > 0; ) {
        // Example: [5, 2, 4, 3, 1] ==> [5, 3, 1, 2, 4]
        // 1. Detect [5, 2 < 4, 3, 1] ; here nums[i] = 2
            if (nums[i] < nums[i + 1]) {
        // 2. Detect 3 is just larger than 2, here nums[j] = 3
                size_t j;
                for (j = nums.size(); j-- > i; ) {
                    if (nums[j] > nums[i]) break;
                }
        // 3. Move nums[j] to first place ==> [5, {3, (2, 4)}, 1]
                int t = nums[j];
                for (size_t k = j; k-- > i; )
                    nums[k + 1] = nums[k];
                nums[i] = t;
        // 4. Sort value after nums[i] = 3 ==> [5, 3, sort(2, 4, 1)] ==> [5, 3 ,1, 2, 4]
                sort(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
    }
};

TEST(e0100, e0031) {
    vector<int> v = str_to_vec<int>("[1,2,3]");
    Solution().nextPermutation(v);
    ASSERT_THAT(v, str_to_vec<int>("[1,3,2]"));
    v = str_to_vec<int>("[3,2,1]");
    Solution().nextPermutation(v);
    ASSERT_THAT(v, str_to_vec<int>("[1,2,3]"));
    v = str_to_vec<int>("[1,1,5]");
    Solution().nextPermutation(v);
    ASSERT_THAT(v, str_to_vec<int>("[1,5,1]"));
}
