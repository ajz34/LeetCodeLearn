// https://leetcode-cn.com/problems/excel-sheet-column-number/

#include "extern.h"

class S0171 {
public:
    int titleToNumber(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            result *= 26;
            result += s[i] - 'A' + 1;
        }
        return result;
    }
};

TEST(e0200, e0171) {
    ASSERT_EQ(S0171().titleToNumber("A"), 1);
    ASSERT_EQ(S0171().titleToNumber("AB"), 28);
    ASSERT_EQ(S0171().titleToNumber("ZY"), 701);
}
