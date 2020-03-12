// https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/

#include "extern.h"

class S1071 {
    int gcdOfInt(int l, int r) {
        if (l < r) swap(l, r);
        while (r != 0) {
            l -= (l / r) * r;
            swap(l, r);
        }
        return l;
    }
    bool isFactorString(const string& str, const string& sub) {
        for (int l = 0; l < str.size(); l += sub.size())
            if (str.substr(l, sub.size()) != sub) return false;
        return true;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.empty() || str2.empty()) return "";
        int si = gcdOfInt(str1.size(), str2.size());

        string strgcd = str1.substr(0, si);
        if (!isFactorString(str1, strgcd)) return "";
        if (!isFactorString(str2, strgcd)) return "";
        return strgcd;
    }
};

TEST(e1100, e1071) {
    string str1, str2;
    str1 = "ABCABC", str2 = "ABC";
    ASSERT_EQ(S1071().gcdOfStrings(str1, str2), "ABC");
    str1 = "ABABAB", str2 = "ABAB";
    ASSERT_EQ(S1071().gcdOfStrings(str1, str2), "AB");
}
