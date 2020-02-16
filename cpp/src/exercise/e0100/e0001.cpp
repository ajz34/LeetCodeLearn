#include "extern.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec{};
        for (int i = 0; i < nums.size(); ++i)
            for (int j = i + 1; j < nums.size(); ++j)
                if (nums[i] + nums[j] == target)
                    return vector<int>{i, j};
        return vec;
    }
};

TEST(e0100, e0001) {
    auto vec = str_to_vect<int>("[2, 7, 11, 15]");
    auto ans = str_to_vect<int>("[0, 1]");
    auto sol = Solution().twoSum(vec, 9);
    ASSERT_THAT(sol, ans);
}
