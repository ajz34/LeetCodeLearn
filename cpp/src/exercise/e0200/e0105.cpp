// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include "extern.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        assert(preorder.size() == inorder.size());
        if (preorder.empty()) return nullptr;
        auto root = new TreeNode(preorder.front());
        auto p = find(inorder.cbegin(), inorder.cend(), preorder.front());
        assert(p != inorder.cend());
        size_t idx = p - inorder.cbegin();
        vector<int> pre, in;
        pre = { preorder.cbegin() + 1, preorder.cbegin() + 1 + idx };
        in = { inorder.cbegin(), inorder.cbegin() + idx };
        root->left = buildTree(pre, in);
        pre = { preorder.cbegin() + 1 + idx, preorder.cend() };
        in = { inorder.cbegin() + 1 + idx, inorder.cend() };
        root->right = buildTree(pre, in);
        return root;
    }
};

TEST(e0200, e0105) {
    vector<int> preorder, inorder;
    preorder = str_to_vec<int>("[3,9,20,15,7]");
    inorder = str_to_vec<int>("[9,3,15,20,7]");
    TreeNode* root = new TreeNode("[3,9,20,null,null,15,7]");
    ASSERT_THAT(Solution().buildTree(preorder, inorder)->to_vector(), root->to_vector());
}
