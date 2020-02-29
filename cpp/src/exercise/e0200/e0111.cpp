// https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/

#include "extern.h"

class S0111 {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (root->left && root->right) return min(minDepth(root->left), minDepth(root->right)) + 1;
        else return max(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

TEST(e0200, e0111) {
    TreeNode* root = new TreeNode("[3,9,20,null,null,15,7]");
    ASSERT_EQ(S0111().minDepth(root), 2);
}
