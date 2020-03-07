// https://leetcode-cn.com/problems/clone-graph/

#include "extern.h"

class S0133 {
public:
    class Node {
    public:
        int val;
        vector<Node*> neighbors;

        Node() {
            val = 0;
            neighbors = vector<Node*>();
        }

        Node(int _val) {
            val = _val;
            neighbors = vector<Node*>();
        }

        Node(int _val, vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
    };
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<int, Node*> clone_map;
        unordered_set<Node*> nodes_prev{ node };
        unordered_set<Node*> nodes_next{};
        clone_map[node->val] = new Node(node->val);
        unordered_set<int> nodes_iterated{ node->val };

        while (!nodes_prev.empty()) {
            nodes_next.clear();
            for (auto ni : nodes_prev) {
                for (auto nj : ni->neighbors) {
                    auto ci = clone_map[ni->val];
                    auto pcj = clone_map.find(nj->val);
                    auto cj = pcj == clone_map.end() ? new Node(nj->val) : pcj->second;
                    if (cj->neighbors.empty()) clone_map[cj->val] = cj;
                    ci->neighbors.push_back(cj);
                    if (nodes_iterated.find(cj->val) == nodes_iterated.end()) {
                        nodes_next.insert(nj);
                        nodes_iterated.insert(nj->val);
                    }
                }
            }
            swap(nodes_prev, nodes_next);
        }
        return clone_map[node->val];
    }
};

// No testing here. Debugging code can be following:

TEST(e0200, e0133) {
    auto n1 = new S0133::Node(1);
    auto n2 = new S0133::Node(2);
    auto n3 = new S0133::Node(3);
    auto n4 = new S0133::Node(4);
    n1->neighbors = { n2, n4 };
    n2->neighbors = { n1, n3 };
    n3->neighbors = { n2, n4 };
    n4->neighbors = { n1, n3 };
    auto c1 = S0133().cloneGraph(n1);
}
