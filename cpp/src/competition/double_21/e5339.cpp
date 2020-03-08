// https://leetcode-cn.com/problems/maximum-sum-bst-in-binary-tree/

#include "extern.h"

class S5339 {
    int MINIMUM = -1000000;
    int maxSumBSTInner(TreeNode* root, int& result) {
        if (!root) return 0;
        int rl = maxSumBSTInner(root->left, result);
        int rr = maxSumBSTInner(root->right, result);
        if ((root->left && root->left->val >= root->val) || (root->right && root->right->val <= root->val) || rl == MINIMUM || rr == MINIMUM) return MINIMUM;
        int r = rl + rr + root->val;
        result = max(r, result);
        return r;
    }
public:
    int maxSumBST(TreeNode* root) {
        int result = 0;
        maxSumBSTInner(root, result);
        return result;
    }
};

TEST(double21, e5339) {
    TreeNode* root;
    root = new TreeNode("[1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]");
    ASSERT_EQ(S5339().maxSumBST(root), 20);
    root = new TreeNode("[4,3,null,1,2]");
    ASSERT_EQ(S5339().maxSumBST(root), 2);
    root = new TreeNode("[-4,-2,-5]");
    ASSERT_EQ(S5339().maxSumBST(root), 0);
    root = new TreeNode("[2,1,3]");
    ASSERT_EQ(S5339().maxSumBST(root), 6);
    root = new TreeNode("[5,4,8,3,null,6,3]");
    ASSERT_EQ(S5339().maxSumBST(root), 7);
}
