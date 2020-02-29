// https://leetcode-cn.com/problems/symmetric-tree/

#include "extern.h"

class Solution {
public:
    bool lrrl(TreeNode* r1, TreeNode* r2) {
        if (!r1) return !r2;
        if (!r2) return false;
        if (r1->val != r2->val) return false;
        return lrrl(r1->left, r2->right) && lrrl(r1->right, r2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return lrrl(root->left, root->right);
    }
};

TEST(e0200, e0101) {
    TreeNode* root;
    root = new TreeNode("[1,2,2,3,4,4,3]");
    ASSERT_TRUE(Solution().isSymmetric(root));
    root = new TreeNode("[1,2,2,null,3,null,3]");
    ASSERT_FALSE(Solution().isSymmetric(root));
}
