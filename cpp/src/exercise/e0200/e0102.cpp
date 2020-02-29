// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

#include "extern.h"

class S0102 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<TreeNode*> que_f, que_s;
        vector<vector<int>> result;
        que_f.push_back(root);
        while (!que_f.empty()) {
            que_s.clear();
            result.push_back({});
            for (auto& t : que_f) {
                result.back().push_back(t->val);
                if (t->left) que_s.push_back(t->left);
                if (t->right) que_s.push_back(t->right);
            }
            swap(que_f, que_s);
        }
        return result;
    }
};

TEST(e0200, e0102) {
    TreeNode* root = new TreeNode("[3,9,20,null,null,15,7]");
    auto ans = str_to_mat<int>("[[3],[9,20],[15,7]]");
    auto res = S0102().levelOrder(root);
    ASSERT_THAT(ans, res);
}
