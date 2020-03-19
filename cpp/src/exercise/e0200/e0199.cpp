// https://leetcode-cn.com/problems/number-of-islands/

#include "extern.h"

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> result;
        vector<TreeNode*> layer_prev{ root }, layer_next;
        while (!layer_prev.empty()) {
            layer_next.clear();
            result.push_back(layer_prev.back()->val);
            for (auto node : layer_prev) {
                if (node->left) layer_next.push_back(node->left);
                if (node->right) layer_next.push_back(node->right);
            }
            swap(layer_prev, layer_next);
        }
        return result;
    }
};

TEST(e0200, e0199) {
    TreeNode* root; vector<int> ans;
    root = new TreeNode("[1,2,3,null,5,null,4]");
    ans = str_to_vec<int>("[1,3,4]");
    ASSERT_THAT(Solution().rightSideView(root), ans);
}
