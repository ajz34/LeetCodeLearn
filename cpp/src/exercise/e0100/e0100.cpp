// https://leetcode-cn.com/problems/same-tree/

#include "extern.h"

class S0100 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p) return !q;
        if (!q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

TEST(e0100, e0100) {
    TreeNode* t1, * t2;
    t1 = new TreeNode("[1,2,3]");
    t2 = new TreeNode("[1,2,3]");
    ASSERT_TRUE(S0100().isSameTree(t1, t2));
    t1 = new TreeNode("[1,2]");
    t2 = new TreeNode("[1,null,2]");
    ASSERT_FALSE(S0100().isSameTree(t1, t2));
    t1 = new TreeNode("[1,2,1]");
    t2 = new TreeNode("[1,1,2]");
    ASSERT_FALSE(S0100().isSameTree(t1, t2));
}
