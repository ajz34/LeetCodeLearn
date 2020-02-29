// https://leetcode-cn.com/problems/recover-binary-search-tree/

#include "extern.h"

class S0099 {
    void leftSearch(TreeNode* root, vector<TreeNode*>& vec) {
        if (root->left) leftSearch(root->left, vec);
        vec.push_back(root);
        if (root->right) leftSearch(root->right, vec);
    }
public:
    void recoverTree(TreeNode* root) {
        if (!root) return;
        vector<TreeNode*> vec;
        leftSearch(root, vec);
        for (int i = 1; i < vec.size(); ++i) {
            if (vec[i]->val < vec[i - 1]->val) {
                int j = i;
                while (j < vec.size() && vec[j]->val < vec[i - 1]->val) ++j;
                swap(vec[j - 1]->val, vec[i - 1]->val);
                break;
            }
        }
    }
};

TEST(e0100, e0099) {
    TreeNode* root, * ans;
    root = new TreeNode("[1,3,null,null,2]");
    ans = new TreeNode("[3,1,null,null,2]");
    S0099().recoverTree(root);
    ASSERT_THAT(root->to_vector(), ans->to_vector());
    root = new TreeNode("[3,1,4,null,null,2]");
    ans = new TreeNode("[2,1,4,null,null,3]");
    S0099().recoverTree(root);
    ASSERT_THAT(root->to_vector(), ans->to_vector());
}
