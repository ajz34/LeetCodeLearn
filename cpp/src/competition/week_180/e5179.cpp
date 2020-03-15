// https://leetcode-cn.com/problems/balance-a-binary-search-tree/

#include "extern.h"

class S5179 {
    void traverseNode(TreeNode* root, vector<TreeNode*>& nodes) {
        if (!root) return;
        nodes.push_back(root);
        traverseNode(root->left, nodes);
        traverseNode(root->right, nodes);
        root->left = nullptr;
        root->right = nullptr;
    }
    struct CompareTree {
        bool operator()(TreeNode* n1, TreeNode* n2) {
            return n1->val < n2->val;
        }
    };
    int constructBST(vector<TreeNode*>& nodes, int l, int r) {
        if (l > r) return -1;
        int m = (l + r) / 2;
        int pl = constructBST(nodes, l, m - 1);
        int pr = constructBST(nodes, m + 1, r);
        nodes[m]->left = (pl != -1) ? nodes[pl] : nullptr;
        nodes[m]->right = (pr != -1) ? nodes[pr] : nullptr;
        return m;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        if (!root) return root;
        vector<TreeNode*> nodes;
        traverseNode(root, nodes);
        sort(nodes.begin(), nodes.end(), CompareTree());
        return nodes[constructBST(nodes, 0, nodes.size() - 1)];
    }
};

/* No testing since testing program need to check whether result is a BST tree. */
