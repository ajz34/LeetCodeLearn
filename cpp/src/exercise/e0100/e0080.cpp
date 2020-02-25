// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/

#include "extern.h"

class Solution {
public:
    int removeDuplicates_e0080(vector<int>& nums) {
        int result = 0;
        auto pc = nums.cend(); int cnt = 0;
        auto pm = nums.begin();
        for (auto p = nums.cbegin(); p != nums.cend(); ++p) {
            if (pc != nums.cend() && *p == *pc) {
                cnt += 1;
                if (cnt <= 2) {
                    result += 1;
                    *(pm++) = *pc;
                }
            }
            else {
                pc = p;
                cnt = 1;
                result += 1;
                (*pm++) = *pc;
            }
        }
        return result;
    }
};

TEST(e0100, e0080) {
    vector<int> nums;
    nums = str_to_vec<int>("[1,1,1,2,2,3]");
    ASSERT_EQ(Solution().removeDuplicates_e0080(nums), 5);
    ASSERT_THAT(vector<int>(nums.begin(), nums.begin() + 5), str_to_vec<int>("[1,1,2,2,3]"));
    nums = str_to_vec<int>("[0,0,1,1,1,1,2,3,3]");
    ASSERT_EQ(Solution().removeDuplicates_e0080(nums), 7);
    ASSERT_THAT(vector<int>(nums.begin(), nums.begin() + 7), str_to_vec<int>("[0,0,1,1,2,3,3]"));
}
