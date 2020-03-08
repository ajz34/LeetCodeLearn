// https://leetcode-cn.com/problems/longest-zigzag-path-in-a-binary-tree/

#include "extern.h"

class S5338 {
    pair<int, int> longestZigZagInner(TreeNode* root, pair<int, int>& result) {
        pair<int, int> r = make_pair(0, 0);
        if (root->left)
            r.first = longestZigZagInner(root->left, result).second + 1;
        if (root->right)
            r.second = longestZigZagInner(root->right, result).first + 1;
        result.first = max(r.first, result.first);
        result.second = max(r.second, result.second);
        return r;
    }
public:
    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        pair<int, int> result = make_pair(0, 0);
        longestZigZagInner(root, result);
        return max(result.first, result.second);
    }
};

TEST(double21, e5338) {
    TreeNode* root;
    root = new TreeNode("[1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]");
    ASSERT_EQ(S5338().longestZigZag(root), 3);
    root = new TreeNode("[1,1,1,null,1,null,null,1,1,null,1]");
    ASSERT_EQ(S5338().longestZigZag(root), 4);
    root = new TreeNode("[1]");
    ASSERT_EQ(S5338().longestZigZag(root), 0);
}
