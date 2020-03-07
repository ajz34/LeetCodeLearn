// https://leetcode-cn.com/problems/copy-list-with-random-pointer/

#include "extern.h"

class S0138 {
public:
    // Definition for a Node.
    class Node {
    public:
        int val;
        Node* next;
        Node* random;

        Node(int _val) {
            val = _val;
            next = NULL;
            random = NULL;
        }
    };
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        vector<Node*> nodes_lst;
        unordered_map<Node*, int> nodes_map;
        auto node = head;
        while (node) {
            nodes_lst.push_back(node);
            nodes_map[node] = nodes_lst.size() - 1;
            node = node->next;
        }
        vector<int> nodes_rand(nodes_map.size(), -1);
        for (int i = 0; i < nodes_lst.size(); ++i) {
            node = nodes_lst[i];
            if (node->random)
                nodes_rand[i] = nodes_map[node->random];
        }

        vector<Node*> clone_lst;
        for (int i = 0; i < nodes_lst.size(); ++i) {
            clone_lst.push_back(new Node(nodes_lst[i]->val));
            if (i > 0) clone_lst[i - 1]->next = clone_lst[i];
        }
        for (int i = 0; i < nodes_lst.size(); ++i) {
            if (nodes_rand[i] != -1)
                clone_lst[i]->random = clone_lst[nodes_rand[i]];
        }
        return clone_lst.front();
    }
};

/* No test here. */
