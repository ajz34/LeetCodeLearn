// https://leetcode-cn.com/problems/generate-a-string-with-characters-that-have-odd-counts/

#include "extern.h"

class S5352 {
public:
    string generateTheString(int n) {
        string s;
        if (n % 2 == 0) {
            for (int i = 0; i < n - 1; ++i) s.push_back('a');
            s.push_back('b');
        }
        else
            for (int i = 0; i < n; ++i) s.push_back('a');
        return s;
    }
};

// No test. This task is simply silly?
