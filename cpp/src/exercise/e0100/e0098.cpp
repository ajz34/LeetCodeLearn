// https://leetcode-cn.com/problems/validate-binary-search-tree/

#include "extern.h"

class S0098 {
    bool leftFirst(TreeNode* root, vector<int>& vec) {
        if (root->left && !leftFirst(root->left, vec)) return false;
        if (!vec.empty() && vec.back() >= root->val) return false;
        vec.push_back(root->val);
        if (root->right && !leftFirst(root->right, vec)) return false;
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        vector<int> vec;
        return leftFirst(root, vec);
    }
};

TEST(e0100, e0098) {
    TreeNode* root;
    root = new TreeNode("[2,1,3]");
    ASSERT_TRUE(S0098().isValidBST(root));
    root = new TreeNode("[5,1,4,null,null,3,6]");
    ASSERT_FALSE(S0098().isValidBST(root));
}
