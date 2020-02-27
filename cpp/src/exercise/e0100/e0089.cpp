// https://leetcode-cn.com/problems/gray-code/

#include "extern.h"

class S0089 {
public:
    vector<int> grayCode(int n) {
        vector<vector<bool>> code;
        if (n == 0) code = { {false} };
        else {
            code = { {false}, {true} };
            for (int i = 2; i <= n; ++i) {
                int cnt = code.size();
                for (auto& c : code) c.push_back(false);
                vector<bool> c_1 = code.back(); c_1[c_1.size() - 1] = true;
                for (int j = 0; j < cnt; ++j) {
                    code.push_back(c_1);
                    const auto& c_in1 = code[j];
                    auto& c_in2 = code[code.size() - 1];
                    for (int k = 0; k < c_in1.size(); ++k)
                        if (c_in1[k]) c_in2[k] = !c_in2[k];
                }
            }
        }
        auto vec_to_int = [](const vector<bool>& c) {
            int result = 0, multplier = 1;
            for (auto v : c) {
                result += v ? multplier : 0;
                multplier *= 2;
            }
            return result;
        };
        vector<int> result;
        for (auto& c : code) result.push_back(vec_to_int(c));
        return result;
    }
};

// No test here since answer is not uniquely defined.
