// https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/

#include "extern.h"

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class S0116 {
public:
    Node* connect(Node* root) {
        if (!root->left) return root;
        connect(root->left);
        connect(root->right);
        Node* l = root->left;
        Node* r = root->right;
        while (l) {
            l->next = r;
            l = l->right;
            r = r->left;
        }
        return root;
    }
};

/* No test here, since the data structure `Node` is less used. */
