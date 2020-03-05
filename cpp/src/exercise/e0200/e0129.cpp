// https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/

#include "extern.h"

class S0129 {
    int digit_to_int(const vector<int>& v) {
        int result = 0;
        for (int i : v) {
            result *= 10;
            result += i;
        }
        return result;
    }
    void sumNumbersInner(TreeNode* root, vector<int>& v, int& result) {
        v.push_back(root->val);
        if (!root->left && !root->right)
            result += digit_to_int(v);
        else {
            if (root->left) sumNumbersInner(root->left, v, result);
            if (root->right) sumNumbersInner(root->right, v, result);
        }
        v.pop_back();
    }
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        vector<int> v{};
        int result = 0;
        sumNumbersInner(root, v, result);
        return result;
    }
};

TEST(e0200, e0129) {
    TreeNode* root;
    root = new TreeNode("[1,2,3]");
    ASSERT_EQ(S0129().sumNumbers(root), 25);
    root = new TreeNode("[4,9,0,5,1]");
    ASSERT_EQ(S0129().sumNumbers(root), 1026);
}
