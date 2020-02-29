#include "extern.h"

class S0106 {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        assert(inorder.size() == postorder.size());
        if (inorder.empty()) return nullptr;
        auto root = new TreeNode(postorder.back());
        auto p = find(inorder.cbegin(), inorder.cend(), root->val);
        size_t idx = p - inorder.cbegin();
        vector<int> in, post;
        in = { inorder.cbegin(), inorder.cbegin() + idx };
        post = { postorder.cbegin(), postorder.cbegin() + idx };
        root->left = buildTree(in, post);
        in = { inorder.cbegin() + idx + 1, inorder.cend() };
        post = { postorder.cbegin() + idx, postorder.cend() - 1 };
        root->right = buildTree(in, post);
        return root;
    }
};

TEST(e0200, e0106) {
    vector<int> inorder, postorder;
    inorder = str_to_vec<int>("[9,3,15,20,7]");
    postorder = str_to_vec<int>("[9,15,7,20,3]");
    TreeNode* root = new TreeNode("[3,9,20,null,null,15,7]");
    ASSERT_THAT(S0106().buildTree(inorder, postorder)->to_vector(), root->to_vector());
}
