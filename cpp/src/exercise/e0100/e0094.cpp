// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/

#include "extern.h"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> result;
        if (root == nullptr) return result;
        stk.push(root);
        while (!stk.empty()) {
            if (stk.top()->left) stk.push(stk.top()->left);
            else {
                while (!stk.empty()) {
                    result.push_back(stk.top()->val);
                    if (stk.top()->right) {
                        TreeNode* pr = stk.top()->right;
                        stk.pop();
                        stk.push(pr);
                        break;
                    }
                    else stk.pop();
                }
            }
        }
        return result;
    }
};

TEST(e0100, e0094) {
    TreeNode* t1 = new TreeNode("[1,null,2,3]");
    vector<int> ans = str_to_vec<int>("[1,3,2]");
    ASSERT_THAT(Solution().inorderTraversal(t1), ans);
}
