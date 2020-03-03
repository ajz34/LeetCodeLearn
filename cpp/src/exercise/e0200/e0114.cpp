// https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/

#include "extern.h"

class S0114 {
    TreeNode* flattenInner(TreeNode* root) {
        if (!root) return nullptr;
        if (root->left) {
            TreeNode* left = flattenInner(root->left);
            left->right = root->right;
            root->right = root->left;
            root->left = nullptr;
            return left->right ? flattenInner(left->right) : left;
        }
        else return root->right ? flattenInner(root->right) : root;
    }
public:
    void flatten(TreeNode* root) {
        flattenInner(root);
    }
};

TEST(e0200, e0114) {
    TreeNode* root = new TreeNode("[1,2,5,3,4,null,6]");
    TreeNode* ans = new TreeNode("[1,null,2,null,3,null,4,null,5,null,6]");
    S0114().flatten(root);
    ASSERT_THAT(root->to_vector(), ans->to_vector());
}
