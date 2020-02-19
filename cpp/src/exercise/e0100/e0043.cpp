// https://leetcode-cn.com/problems/multiply-strings/

#include "extern.h"

class Solution {
public:
    vector<int> bigsum(const vector<int>& num1, const vector<int>& num2) {
        vector<int> res(max(num1.size(), num2.size()) + 1);
        auto p1 = num1.crbegin(), p2 = num2.crbegin();
        auto pr = res.rbegin();
        int up = 0, stage = 0;
        while (p1 != num1.crend() && p2 != num2.crend()) {
            stage = *(p1++) + *(p2++) + up;
            up = stage / 10;
            *(pr++) = stage % 10;
        }
        while (p1 != num1.crend()) {
            stage = *(p1++) + up;
            up = stage / 10;
            *(pr++) = stage % 10;
        }
        while (p2 != num2.crend()) {
            stage = *(p2++) + up;
            up = stage / 10;
            *(pr++) = stage % 10;
        }
        if (up == 1) *pr = 1;
        auto pl = res.cbegin();
        while (pl != res.cend() && *pl == 0) { ++pl; }
        return { pl, res.cend() };
    }

    vector<int> mult_less10(const vector<int>& num, int m) {
        if (m == 0) return {};
        vector<int> res(num.size() + 1, 0);
        auto p = num.crbegin(); auto pr = res.rbegin();
        int stage = 0, up = 0;
        while (p != num.crend()) {
            stage = *(p++) * m + up;
            up = stage / 10;
            *(pr++) = stage % 10;
        }
        if (up != 0) *pr = up;
        auto pl = res.cbegin();
        while (pl != res.cend() && *pl == 0) { ++pl; }
        return { pl, res.cend() };
    }

    string multiply(const string& num1, const string& num2) {
        vector<int> n1(num1.size(), 0), n2(num2.size(), 0);
        for (int i = 0; i < num1.size(); ++i) n1[i] = num1[i] - '0';
        for (int i = 0; i < num2.size(); ++i) n2[i] = num2[i] - '0';
        vector<int> r;
        for (int i = 0; i < num2.size(); ++i) {
            vector<int> vt = mult_less10(n1, n2[num2.size() - i - 1]);
            for (int j = 0; j < i; ++j) vt.push_back(0);
            r = bigsum(r, vt);
        }
        string res(r.size(), '0');
        for (int i = 0; i < r.size(); ++i)
            res[i] += r[i];
        if (res.size() == 0) res = "0";
        return res;
    }
};

TEST(e0100, e0043) {
    string s1 = "123", s2 = "456";
    ASSERT_EQ(Solution().multiply(s1, s2), "56088");
}
