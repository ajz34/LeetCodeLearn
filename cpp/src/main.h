//
// Created by ajz34 on 2020/2/9.
//

#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    for (size_t idx = 0; idx < vec.size(); ++idx) {
        os << vec[idx];
        if (idx < vec.size() - 1) os << ", ";
    }
    return os;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(const vector<int>& v) : val(v[0]), next(nullptr) {
        auto p = this;
        for (size_t i = 1; i < v.size(); ++i) {
            p->next = new ListNode(v[i]);
            p = p->next;
        }
    }
    vector<int> to_vector() {
        auto p = this;
        vector<int> v;
        while (p) {
            v.push_back(p->val);
            p = p->next;
        }
        return v;
    }
};

#endif
