// https://leetcode-cn.com/problems/binary-search-tree-iterator/

#include "extern.h"

class BSTIterator0173 {
    stack<TreeNode*> stk;
    void update_node(TreeNode* node) {
        while (node) {
            stk.push(node);
            node = node->left;
        }
    }
public:
    BSTIterator0173(TreeNode* root) {
        update_node(root);
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* top = stk.top();
        stk.pop();
        if (top->right)
            update_node(top->right);
        return top->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }
};

TEST(e0200, e0173) {
    TreeNode* root = new TreeNode("[7,3,15,null,null,9,20]");
    BSTIterator0173 iterator = BSTIterator0173(root);
    ASSERT_EQ(iterator.next(), 3);
    ASSERT_EQ(iterator.next(), 7);
    ASSERT_EQ(iterator.hasNext(), true);
    ASSERT_EQ(iterator.next(), 9);
    ASSERT_EQ(iterator.hasNext(), true);
    ASSERT_EQ(iterator.next(), 15);
    ASSERT_EQ(iterator.hasNext(), true);
    ASSERT_EQ(iterator.next(), 20);
    ASSERT_EQ(iterator.hasNext(), false);
}
