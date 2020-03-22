// https://leetcode-cn.com/problems/create-target-array-in-the-given-order/

#include "extern.h"

class S5364 {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            result.insert(result.begin() + index[i], nums[i]);
        }
        return result;
    }
};

TEST(week181, e5364) {
    vector<int> nums, index, ans;
    nums = str_to_vec<int>("[0,1,2,3,4]");
    index = str_to_vec<int>("[0,1,2,2,1]");
    ans = str_to_vec<int>("[0,4,1,3,2]");
    ASSERT_THAT(S5364().createTargetArray(nums, index), ans);
    nums = str_to_vec<int>("[1,2,3,4,0]");
    index = str_to_vec<int>("[0,1,2,3,0]");
    ans = str_to_vec<int>("[0,1,2,3,4]");
    ASSERT_THAT(S5364().createTargetArray(nums, index), ans);
    nums = str_to_vec<int>("[1]");
    index = str_to_vec<int>("[0]");
    ans = str_to_vec<int>("[1]");
    ASSERT_THAT(S5364().createTargetArray(nums, index), ans);
}
