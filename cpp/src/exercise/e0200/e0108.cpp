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

// No test because answer is not unique.
