// https://leetcode-cn.com/problems/binary-tree-postorder-traversal/

#include "extern.h"

class S0145 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> result;
        TreeNode* node = root;
        stack<TreeNode*> stk; stk.push(root);
        while (!stk.empty()) {
            if (stk.top()->left)
                stk.push(stk.top()->left);
            else if (stk.top()->right)
                stk.push(stk.top()->right);
            else {
                while (true) {
                    node = stk.top(); stk.pop();
                    result.push_back(node->val);
                    if (stk.empty()) return result;
                    if (node == stk.top()->left && stk.top()->right) {
                        stk.push(stk.top()->right);
                        break;
                    }
                }
            }
        }
        return result;
    }
};

TEST(e0200, e0145) {
    TreeNode* root = new TreeNode("[1,null,2,3]");
    vector<int> ans = str_to_vec<int>("[3,2,1]");
    ASSERT_THAT(S0145().postorderTraversal(root), ans);
}
