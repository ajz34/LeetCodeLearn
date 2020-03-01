// https://leetcode-cn.com/problems/linked-list-in-binary-tree/

#include "extern.h"

class S5346_slow {
    bool subPath(ListNode* head, TreeNode* root, ListNode* head_len, TreeNode* root_hgt, int hl) {
        if (!head) return true;
        if (!root) return false;
        if (root_hgt->val < head_len->val) return false;
        if (head->val == root->val) {
            if (subPath(head->next, root->left, head_len->next, root_hgt->left, hl)) return true;
            if (subPath(head->next, root->right, head_len->next, root_hgt->right, hl)) return true;
        }
        if (head->val != hl) return false;
        else {
            if (subPath(head, root->left, head_len, root_hgt->left, hl)) return true;
            if (subPath(head, root->right, head_len, root_hgt->right, hl)) return true;
            return false;
        }
    }
    ListNode* gen_head_len(ListNode* head) {
        if (!head->next) return new ListNode(1);
        else {
            ListNode* n = gen_head_len(head->next);
            ListNode* r = new ListNode(n->val + 1);
            r->next = n;
            return r;
        }
    }
    TreeNode* gen_root_hgt(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* rl = gen_root_hgt(root->left), * rr = gen_root_hgt(root->right);
        int height = 0;
        if (rl) height = max(rl->val, height);
        if (rr) height = max(rr->val, height);
        height += 1;
        TreeNode* r = new TreeNode(height);
        r->left = rl; r->right = rr;
        return r;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        ListNode* head_len = gen_head_len(head);
        TreeNode* root_hgt = gen_root_hgt(root);
        return subPath(head, root, head_len, root_hgt, head->val);
    }
};

class S5346 {
public:
    bool dfs(ListNode* head, TreeNode* root) {
        if (!head) return true;
        if (!root) return false;
        if (root->val != head->val) return false;
        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head) return true;
        if (!root) return false;
        if (dfs(head, root)) return true;
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

TEST(week178, e5346) {
    ListNode* head; TreeNode* root;
    head = new ListNode("[4,2,8]");
    root = new TreeNode("[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]");
    ASSERT_TRUE(S5346().isSubPath(head, root));
    head = new ListNode("[1,4,2,6]");
    root = new TreeNode("[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]");
    ASSERT_TRUE(S5346().isSubPath(head, root));
    head = new ListNode("[1,4,2,6,8]");
    root = new TreeNode("[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]");
    ASSERT_FALSE(S5346().isSubPath(head, root));
}

/* 上述代码并非我自己所写。我原先的代码对树长度作判断，太过冗长。 */
