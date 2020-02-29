// https://leetcode-cn.com/problems/balanced-binary-tree/

#include "extern.h"

class S0110 {
public:
    int depth(TreeNode* root, bool& stat) {
        if (!stat) return -1;
        if (!root) return 0;
        int dep_l = depth(root->left, stat); if (!stat) return -1;
        int dep_r = depth(root->right, stat); if (!stat) return -1;
        if (abs(dep_l - dep_r) >= 2) { stat = false; return -1; }
        return max(dep_l, dep_r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool stat = true;
        depth(root, stat);
        return stat;
    }
};

TEST(e0200, e0110) {
    TreeNode* root;
    root = new TreeNode("[3,9,20,null,null,15,7]");
    ASSERT_TRUE(S0110().isBalanced(root));
    root = new TreeNode("[1,2,2,3,3,null,null,4,4]");
    ASSERT_FALSE(S0110().isBalanced(root));
}
