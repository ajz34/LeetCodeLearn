// https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/

#include "extern.h"

class S0108 {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        size_t idx = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[idx]);
        vector<int> nums_left = { nums.begin(), nums.begin() + idx };
        vector<int> nums_right = { nums.begin() + idx + 1, nums.end() };
        root->left = sortedArrayToBST(nums_left);
        root->right = sortedArrayToBST(nums_right);
        return root;
    }
};

TEST(e0200, e0108) {
    vector<int> nums = str_to_vec<int>("[-10,-3,0,5,9]");
    TreeNode* ans = new TreeNode("[0,-3,9,-10,null,5]");
    ASSERT_THAT(S0108().sortedArrayToBST(nums)->to_vector(), ans->to_vector());
}
