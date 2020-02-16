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

#pragma region Display

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    for (size_t idx = 0; idx < vec.size(); ++idx) {
        os << vec[idx];
        if (idx < vec.size() - 1) os << ", ";
    }
    return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& vec) {
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

#pragma endregion

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

template<class T>
vector<T> str_to_vect(const string& s) {
    assert(s.size() >= 2);
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
vector<vector<T>> str_to_mat(const string& s) {
    assert(s.size() >= 2);
    assert(s.front() == '[' && s.back() == ']');
    vector<vector<T>> result{};
    size_t il = 1, ir = 1;
    for (; ir < s.size() - 1; ++ir) {
        if (s[ir] == '[') il = ir;
        else if (s[ir] == ']') result.push_back(str_to_vect<T>(s.substr(il, ir - il + 1)));
    }
    return result;
}

#pragma endregion