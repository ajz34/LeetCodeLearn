//
// Created by ajz34 on 2020/2/9.
//

#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    for (int idx = 0; idx < vec.size(); ++idx) {
        os << vec[idx];
        if (idx < vec.size() - 1) os << ", ";
    }
    return os;
}

#endif
