// https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/

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

class S0117 {
    vector<Node*> node_next;
    void connectHeight(Node* root, int height) {
        if (!root) return;
        if (node_next.size() <= height)
            node_next.push_back(root);
        else {
            node_next[height]->next = root;
            node_next[height] = root;
        }
        connectHeight(root->left, height + 1);
        connectHeight(root->right, height + 1);
    }
public:
    Node* connect(Node* root) {
        connectHeight(root, 0);
        return root;
    }
};

/* No test here, since the data structure `Node` is less used. */
