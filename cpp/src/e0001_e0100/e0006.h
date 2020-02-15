//
// Created by ajz34 on 2020/2/11.
//

#ifndef E0006_ZIGZAG_CONVERSION_H
#define E0006_ZIGZAG_CONVERSION_H

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // let n = numRows, N = 2n - 2
        // row i: i, N - i, N + i, 2N - i, ...
        if (s.empty()) return "";
        if (numRows == 1) return s;
        string r;
        int n = numRows; int N = 2 * n - 2; int size = s.size();
        for (int i = 0; i < n; ++i) {
            int m = 0;
            while (true) {
                if (m * N + i < size)
                    r.push_back(s[m * N + i]);
                else break;
                ++m;
                if (i == 0 || i == n - 1) continue;
                if (m * N - i < size)
                    r.push_back((s[m * N - i]));
                else break;
            }
        }
        return r;
    }
};

#endif //TEST_CPP_E0006_ZIGZAG_CONVERSION_H
