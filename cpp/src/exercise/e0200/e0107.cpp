// https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/

#include "extern.h"

class S0107 {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        vector<vector<TreeNode*>> vec;
        vec.push_back({ {root} });
        while (!vec.back().empty()) {
            auto vb = vec.back();
            vec.push_back({});
            for (auto& t : vb) {
                if (t->left) vec.back().push_back(t->left);
                if (t->right) vec.back().push_back(t->right);
            }
        }
        vec.pop_back();
        vector<vector<int>> result;
        for (auto p = vec.rbegin(); p != vec.rend(); ++p) {
            result.push_back({});
            for (auto t : *p) result.back().push_back(t->val);
        }
        return result;
    }
};

TEST(e0200, e0107) {
    TreeNode* root = new TreeNode("[3,9,20,null,null,15,7]");
    auto ans = str_to_mat<int>("[[15,7],[9,20],[3]]");
    ASSERT_THAT(S0107().levelOrderBottom(root), ans);
}
