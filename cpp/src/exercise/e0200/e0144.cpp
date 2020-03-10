// https://leetcode-cn.com/problems/binary-tree-preorder-traversal/

#include "extern.h"

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> que; que.push(root);
        TreeNode* cur;
        vector<int> result;
        while (!que.empty()) {
            cur = que.top(); que.pop();
            result.push_back(cur->val);
            if (cur->right) que.push(cur->right);
            if (cur->left) que.push(cur->left);
        }
        return result;
    }
};

TEST(e0200, e0144) {
    TreeNode* root = new TreeNode("[1,2,3,4,5,6,7]");
    vector<int> ans = str_to_vec<int>("[1,2,4,5,3,6,7]");
    ASSERT_THAT(Solution().preorderTraversal(root), ans);
}
