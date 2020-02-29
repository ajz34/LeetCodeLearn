// https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/

#include "extern.h"

class S0104 {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

TEST(e0200, e0104) {
    auto root = new TreeNode("[3,9,20,null,null,15,7]");
    ASSERT_EQ(S0104().maxDepth(root), 3);
}
