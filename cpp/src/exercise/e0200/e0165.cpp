// https://leetcode-cn.com/problems/compare-version-numbers/

#include "extern.h"

class S0165 {
    vector<int> splitDot(string& s) {
        vector<int> result;
        int l = 0;
        for (int r = 0; r < s.size(); ++r) {
            if (s[r] == '.') {
                result.push_back(stoi(s.substr(l, r + 1 - l)));
                l = r + 1;
            }
        }
        result.push_back(stoi(s.substr(l)));
        return result;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = splitDot(version1), v2 = splitDot(version2);
        while (v1.size() < v2.size()) v1.push_back(0);
        while (v2.size() < v1.size()) v2.push_back(0);
        for (int i = 0; i < v1.size(); ++i) {
            if (v1[i] < v2[i]) return -1;
            else if (v1[i] > v2[i]) return 1;
        }
        return 0;
    }
};

TEST(e0200, e0165) {
    string version1, version2;
    version1 = "0.1", version2 = "1.1";
    ASSERT_EQ(S0165().compareVersion(version1, version2), -1);
    version1 = "1.0.1", version2 = "1";
    ASSERT_EQ(S0165().compareVersion(version1, version2), 1);
}
