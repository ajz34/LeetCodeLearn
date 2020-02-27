//
// Created by ajz34 on 2020/2/9.
//

#pragma once

#include "gtest/gtest.h"
#include "gmock/gmock.h"
using namespace testing;

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <regex>
#include <cassert>
using namespace std;

#pragma region Vector Conversion

// https://stackoverflow.com/a/29892589/9647779

string& ltrim(string& str);
string& rtrim(string& str);
string& trim(string& str);

// Convert string `[a, b, c, ...]` to vector<T> { a, b, c, ... } by common 

template<class T>
struct Converter { inline T operator()(const string& s) { return T(); } };

template<>
struct Converter<int> { inline int operator()(const string& s) { return atoi(s.c_str()); } };

template<>
struct Converter<string> {
    inline string operator()(const string& s) {
        if (s.empty()) return s;
        if (s.front() == s.back() && (s.front() == '\"' || s.front() == '\'')) return s.substr(1, s.size() - 1);
        return s;
    }
};

template<>
struct Converter<char> {
    inline char operator()(const string& s) {
        assert(!s.empty());
        if (s.front() == s.back() && (s.front() == '\"' || s.front() == '\'')) {
            assert(s.size() == 3);
            return s[1];
        }
        assert(s.size() == 1);
        return s[0];
    }
};

template<class T>
vector<T> str_to_vec(string&& s_) {
    auto s = trim(s_);
    assert(s.size() >= 2);
    if (s.size() == 2) return {};
    assert(s.front() == '[' && s.back() == ']');
    vector<T> result{};
    stringstream ss(s.substr(1, s.size() - 2));
    while (ss.good()) {
        string subs{};
        getline(ss, subs, ',');
        result.push_back(Converter<T>()(trim(subs)));
    }
    return result;
}

template<class T>
vector<vector<T>> str_to_mat(string&& s_) {
    auto s = trim(s_);
    assert(s.size() >= 2);
    assert(s.front() == '[' && s.back() == ']');
    vector<vector<T>> result{};
    size_t il = 1, ir = 1;
    for (; ir < s.size() - 1; ++ir) {
        if (s[ir] == '[') il = ir;
        else if (s[ir] == ']') result.push_back(str_to_vec<T>(s.substr(il, ir - il + 1)));
    }
    return result;
}

#pragma endregion

#pragma region ListNode

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(const vector<int>& v) : val(v[0]), next(nullptr) {
        auto p = this;
        for (size_t i = 1; i < v.size(); ++i) {
            p->next = new ListNode(v[i]);
            p = p->next;
        }
    }
    ListNode(string&& s) : next(nullptr) {
        vector<int> v = str_to_vec<int>(move(s));
        val = v[0];
        auto p = this;
        for (size_t i = 1; i < v.size(); ++i) {
            p->next = new ListNode(v[i]);
            p = p->next;
        }
    }
    vector<int> to_vector() const {
        auto p = this;
        vector<int> v;
        while (p) {
            v.push_back(p->val);
            p = p->next;
        }
        return v;
    }
};

#pragma endregion

#pragma region TreeNode

struct TreeNode {
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(string&& s) {
        assert(s.size() > 2);
        assert(s.front() == '[' && s.back() == ']');
        size_t pl = 1, pr = pl;
        queue<TreeNode*> vec;
        while (pr < s.size() - 1) {
            pr = s.find(',', pl);
            if (pr == -1) pr = s.size() - 1;
            string subs = s.substr(pl, pr - pl);
            subs = trim(subs);
            if (subs == "null") vec.push(nullptr);
            else vec.push(new TreeNode(stoi(subs)));
            pl = pr + 1;
        }
        queue<TreeNode*> que;
        TreeNode* head = vec.front();
        this->val = head->val;
        que.push(this); vec.pop();
        while (!vec.empty()) {
            que.front()->left = vec.front();
            if (vec.front()) que.push(vec.front());
            vec.pop();
            if (vec.empty()) break;
            que.front()->right = vec.front();
            if (vec.front()) que.push(vec.front());
            vec.pop();
            que.pop();
        }
    }
    vector<string> to_vector() const {
        queue<const TreeNode*> que; que.push(this);
        vector<string> s{ to_string(this->val) };
        while (!que.empty()) {
            const TreeNode* pl = que.front()->left;
            const TreeNode* pr = que.front()->right;
            s.push_back(pl ? to_string(pl->val) : "null");
            s.push_back(pr ? to_string(pr->val) : "null");
            if (pl) que.push(pl); if (pr) que.push(pr);
            que.pop();
        }
        while (s.back() == "null") s.pop_back();
        return s;
    }
};

#pragma endregion

#pragma region Display

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    if (vec.empty()) return (os << "[]");
    os << "[ ";
    for (size_t idx = 0; idx < vec.size(); ++idx) {
        os << vec[idx];
        if (idx < vec.size() - 1) os << ", ";
    }
    os << " ]";
    return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& vec) {
    if (vec.empty()) {
        os << "[-> [] <-]";
        return os;
    }
    for (size_t idx = 0; idx < vec.size(); ++idx) {
        if (idx == 0) {
            os << "[-> " << vec[idx];
            if (vec.size() == 1) os << " <-]";
            else os << endl;
        }
        else if (idx == vec.size() - 1)
            os << "[<- " << vec[idx];
        else
            os << "[   " << vec[idx] << endl;
    }
    return os;
}

ostream& operator<<(ostream& os, ListNode* l);
ostream& operator<<(ostream& os, TreeNode* t);

#pragma endregion
