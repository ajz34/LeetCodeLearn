// https://leetcode-cn.com/problems/decode-ways/

#include "extern.h"

class S0091 {
public:
    int numDecodings(string s) {
        auto valid_char = [](const string& cs) {
            switch (cs.size()) {
            case 1: return cs[0] != '0';
            case 2:
                switch (cs[0]) {
                case '1': return true;
                case '2': if (cs[1] <= '6') return true; else return false;
                default: return false;
                }
            default: assert(false);
            }
        };
        vector<int> s_res(s.size(), 0);
        s_res[0] = valid_char(s.substr(0, 1)) ? 1 : 0; if (s_res[0] == 0) return 0;
        for (int i = 1; i < s.size(); ++i) {
            if (valid_char(s.substr(i, 1))) s_res[i] = s_res[i - 1];
            if (valid_char(s.substr(i - 1, 2)))
                if (i > 1) s_res[i] += s_res[i - 2];
                else s_res[i] += 1;
        }
        return s_res.back();
    }
};

TEST(e0100, e0091) {
    ASSERT_EQ(S0091().numDecodings("12"), 2);
    ASSERT_EQ(S0091().numDecodings("226"), 3);
}
