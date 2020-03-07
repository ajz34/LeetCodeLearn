#include "extern.h"

class S0132 {
public:
    int minCut(string s) {
        int INFTY = 10000000;
        if (s.empty()) return 0;
        vector<vector<int>> stat(s.size(), vector<int>{});
        for (int i = 0; i < 2 * s.size() - 1; ++i) {
            int l = i / 2, r = (i + 1) / 2;
            while (l >= 0 && r < s.size()) {
                if (s[l] == s[r]) stat[l].push_back(r);
                else break;
                --l, ++r;
            }
        }
        vector<int> result(s.size(), INFTY);
        for (int l = s.size(); l-- > 0;) {
            for (int r : stat[l]) {
                if (r + 1 == s.size())
                    result[l] = min(1, result[l]);
                else
                    result[l] = min(result[r + 1] + 1, result[l]);
            }
        }
        return result[0] - 1;
    }
};

TEST(e0200, e0132) {
    ASSERT_EQ(S0132().minCut("aab"), 1);
}
