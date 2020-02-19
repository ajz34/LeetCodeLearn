// https://leetcode-cn.com/problems/first-missing-positive/

#include "extern.h"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int s = int(nums.size()); nums.push_back(0);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == i) continue;
            if (nums[i] < 1 || nums[i] > s) continue;
            int j = nums[i];
            while (j > 0 && j <= s && nums[j] != j) {
                int t = nums[j];
                nums[j] = j;
                j = t;
            }
        }
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] != i) return i;
        return s + 1;
    }
};

TEST(e0100, e0041) {
    vector<int> v = str_to_vec<int>("[1,2,0]");
    ASSERT_EQ(Solution().firstMissingPositive(v), 3);
    v = str_to_vec<int>("[3,4,-1,1]");
    ASSERT_EQ(Solution().firstMissingPositive(v), 2);
    v = str_to_vec<int>("[7,8,9,11,12]");
    ASSERT_EQ(Solution().firstMissingPositive(v), 1);
}
