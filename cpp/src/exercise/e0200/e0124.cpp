// https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/

#include "extern.h"

class S0124 {
    int max_val = -2147483648;
    inline int max_3(int a, int b, int c) { return max(max(a, b), c); }
    int maxPathSumInner(TreeNode* root) {
        if (!root) return 0;
        int res_l = maxPathSumInner(root->left);
        int res_r = maxPathSumInner(root->right);
        int result = max_3(root->val + res_l, root->val + res_r, root->val);
        max_val = max_3(result, root->val + res_l + res_r, max_val);
        return result;
    }
public:
    int maxPathSum(TreeNode* root) {
        maxPathSumInner(root);
        return max_val;
    }
};

TEST(e0200, e0124) {
    TreeNode* root;
    root = new TreeNode("[1,2,3]");
    ASSERT_EQ(S0124().maxPathSum(root), 6);
    root = new TreeNode("[-10,9,20,null,null,15,7]");
    ASSERT_EQ(S0124().maxPathSum(root), 42);
}
