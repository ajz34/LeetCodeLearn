// https://leetcode-cn.com/problems/add-binary/

#include "extern.h"

class Solution {
    void reverseStringInplace(string& s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) swap(s[i], s[j]);
    }
public:
    string addBinary(string a, string b) {
        reverseStringInplace(a); reverseStringInplace(b);
        string result;
        int plus1 = 0;
        for (int i = 0; i < max(a.size(), b.size()); ++i) {
            int v = plus1;
            if (i < a.size()) v += a[i] - '0';
            if (i < b.size()) v += b[i] - '0';
            if (v >= 2) { v -= 2; plus1 = 1; }
            else plus1 = 0;
            result += v + '0';
        }
        if (plus1 == 1) result += '1';
        reverseStringInplace(result);
        while (!result.empty() && result.back() == 0) result.pop_back();
        if (result.empty()) return "0";
        return result;
    }
};

TEST(e0100, e0067) {
    ASSERT_EQ(Solution().addBinary("11", "1"), "100");
    ASSERT_EQ(Solution().addBinary("1010", "1011"), "10101");
}
