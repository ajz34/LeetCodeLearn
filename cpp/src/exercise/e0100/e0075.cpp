#include "extern.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // TODO: Try the original netherland flag problem
        // https://leetcode-cn.com/problems/sort-colors/solution/yan-se-fen-lei-by-leetcode/
        if (nums.size() <= 1) return;
        int p0 = 0, pcur = 0, p2 = nums.size() - 1;
        while (pcur <= p2) {
            if (nums[pcur] == 2) swap(nums[pcur], nums[p2--]);
            else if (nums[pcur] == 0) swap(nums[pcur++], nums[p0++]);
            else ++pcur;
        }
    }
    void sortColors_Easy(vector<int>& nums) {
        vector<int> cnt(3, 0);
        for (auto n : nums) ++cnt[n];
        int p = 0;
        for (int value = 0; value < 3; ++value)
            for (int n = 0; n < cnt[value]; ++n)
                nums[p++] = value;
    }
};

TEST(e0100, e0075) {
    vector<int> vec, ans;
    vec = str_to_vec<int>("[2,0,2,1,1,0]");
    ans = str_to_vec<int>("[0,0,1,1,2,2]");
    Solution().sortColors(vec);
    ASSERT_THAT(vec, ans);
}
