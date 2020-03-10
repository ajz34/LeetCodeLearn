// https://leetcode-cn.com/problems/diameter-of-binary-tree/

#include "extern.h"

class S0543 {
    int diameterOfBinaryTreeInner(TreeNode* root, int& result) {
        if (!root) return -1;
        int dl = diameterOfBinaryTreeInner(root->left, result);
        int dr = diameterOfBinaryTreeInner(root->right, result);
        result = max(dl + dr + 2, result);
        return max(dl + 1, dr + 1);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int result = 0;
        diameterOfBinaryTreeInner(root, result);
        return result;
    }
};

TEST(e0600, e0543) {
    TreeNode* root = new TreeNode("[1,2,3,4,5]");
    ASSERT_EQ(S0543().diameterOfBinaryTree(root), 3);
}
