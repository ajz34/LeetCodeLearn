// https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/

#include "extern.h"

class S0103 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        bool zigzag = false;
        vector<TreeNode*> que_f, que_s;
        vector<vector<int>> result;
        que_f.push_back(root);
        while (!que_f.empty()) {
            que_s.clear();
            for (auto t : que_f) {
                if (t->left) que_s.push_back(t->left);
                if (t->right) que_s.push_back(t->right);
            }
            result.push_back({}); auto& v = result.back();
            if (zigzag) for (size_t i = que_f.size(); i-- > 0;) v.push_back(que_f[i]->val);
            else for (size_t i = 0; i < que_f.size(); ++i) v.push_back(que_f[i]->val);
            swap(que_f, que_s);
            zigzag = !zigzag;
        }
        return result;
    }
};

TEST(e0200, e0103) {
    TreeNode* root = new TreeNode("[3,9,20,null,null,15,7]");
    auto res = S0103().zigzagLevelOrder(root);
    auto ans = str_to_mat<int>("[[3],[20,9],[15,7]]");
    ASSERT_THAT(res, ans);
}
