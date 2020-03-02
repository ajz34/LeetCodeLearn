// https://leetcode-cn.com/problems/path-sum/

#include "extern.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right) return sum == root->val;
        if (root->left && hasPathSum(root->left, sum - root->val)) return true;
        if (root->right && hasPathSum(root->right, sum - root->val)) return true;
        return false;
    }
};

TEST(e0200, e0112) {
    TreeNode* root;
    root = new TreeNode("[5,4,8,11,null,13,4,7,2,null,null,null,1]");
    ASSERT_TRUE(Solution().hasPathSum(root, 22));
}
