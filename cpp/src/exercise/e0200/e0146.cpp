// https://leetcode-cn.com/problems/lru-cache/

#include "extern.h"

class LRUCache0146 {
    struct Node {
        pair<int, int>* val;
        Node* next = nullptr;
        Node* prev = nullptr;
        Node(pair<int, int>* p) : val(p) {}
    };

    int _capacity = 0;
    unordered_map<int, Node*> _map;
    Node* _head = new Node(nullptr);
    Node* _tail = new Node(nullptr);

    void move_to_last(unordered_map<int, Node*>::iterator p) {
        auto n = p->second;

        auto np = n->prev, nn = n->next;
        np->next = nn; nn->prev = np;

        auto tp = _tail->prev;
        tp->next = n; n->prev = tp;
        n->next = _tail; _tail->prev = n;
    }

    void delete_head() {
        if (_head->next == _tail) return;
        auto n = _head->next, nn = n->next;
        _head->next = nn; nn->prev = _head;
        _map.erase(n->val->first);
        delete n;
    }

public:
    LRUCache0146(int capacity) : _capacity(capacity) {
        _head->next = _tail;
        _tail->prev = _head;
    }

    int get(int key) {
        auto p = _map.find(key);
        if (p == _map.end())
            return -1;
        move_to_last(p);
        return p->second->val->second;
    }

    void put(int key, int value) {
        auto p = _map.find(key);
        if (p != _map.end()) {
            p->second->val->second = value;
            move_to_last(p);
        }
        else {
            if (_map.size() == _capacity)
                delete_head();
            Node* n = new Node(new pair<int, int>{ key, value });
            _map[key] = n;

            auto tp = _tail->prev;
            tp->next = n; n->prev = tp;
            n->next = _tail; _tail->prev = n;
        }
    }
};

TEST(e0200, e0146) {
    LRUCache0146 cache = LRUCache0146(2);
    cache.put(1, 1);
    cache.put(2, 2);
    ASSERT_EQ(cache.get(1), 1);
    cache.put(3, 3);
    ASSERT_EQ(cache.get(2), -1);
    cache.put(4, 4);
    ASSERT_EQ(cache.get(1), -1);
    ASSERT_EQ(cache.get(3), 3);
    ASSERT_EQ(cache.get(4), 4);
}
