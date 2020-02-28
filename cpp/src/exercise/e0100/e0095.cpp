// https://leetcode-cn.com/problems/unique-binary-search-trees-ii/

#include "extern.h"

class S0095 {
public:
    TreeNode* copyTree(TreeNode* t, int pv = 0) {
        if (!t) return nullptr;
        TreeNode* r = new TreeNode(t->val + pv);
        r->left = copyTree(t->left, pv);
        r->right = copyTree(t->right, pv);
        return r;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        vector<vector<TreeNode*>> res_mat(n + 1, vector<TreeNode*>{});
        res_mat[0] = { nullptr };
        res_mat[1] = { new TreeNode(1) };
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                int k = i - 1 - j;
                for (TreeNode* tj : res_mat[j]) {
                    for (TreeNode* tk : res_mat[k]) {
                        auto t = new TreeNode(j + 1);
                        t->left = copyTree(tj);
                        t->right = copyTree(tk, j + 1);
                        res_mat[i].push_back(t);
                    }
                }
            }
        }
        return res_mat[n];
    }
};

TEST(e0100, e0095) {
    auto res = S0095().generateTrees(3);
    set<vector<string>> res_str;
    for (auto r : res) res_str.insert(r->to_vector());
    vector<TreeNode*> ans{
        new TreeNode("[1,null,2,null,3]"),
        new TreeNode("[1,null,3,2]"),
        new TreeNode("[2,1,3]"),
        new TreeNode("[3,1,null,null,2]"),
        new TreeNode("[3,2,null,1]"),
    };
    set<vector<string>> ans_str;
    for (auto r : ans) ans_str.insert(r->to_vector());
    ASSERT_THAT(res_str, ans_str);
}
