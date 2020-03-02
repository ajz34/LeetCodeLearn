// https://leetcode-cn.com/problems/path-sum-ii/

#include "extern.h"

class Solution {
    void pathSumInner(TreeNode* root, int sum, vector<int>& vec, vector<vector<int>>& result) {
        if (!root) return;
        vec.push_back(root->val);
        if (!root->left && !root->right && sum == root->val)
            result.push_back(vec);
        else {
            if (root->left)
                pathSumInner(root->left, sum - root->val, vec, result);
            if (root->right)
                pathSumInner(root->right, sum - root->val, vec, result);
        }
        vec.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> vec;
        vector<vector<int>> result;
        pathSumInner(root, sum, vec, result);
        return result;
    }
};

TEST(e0200, e0113) {
    TreeNode* root;
    root = new TreeNode("[5,4,8,11,null,13,4,7,2,null,null,5,1]");
    auto res = vec_to_set<vector<int>>(Solution().pathSum(root, 22));
    auto ans = vec_to_set<vector<int>>(str_to_mat<int>("[[5,4,11,2],[5,8,4,5]]"));
    cout << Solution().pathSum(root, 22) << endl;
}
