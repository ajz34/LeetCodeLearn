// https://leetcode-cn.com/problems/excel-sheet-column-title/

#include "extern.h"

class S0168 {
public:
    string convertToTitle(int n) {
        string result;
        while (n != 0) {
            result += 'A' + ((n - 1) % 26);
            n = (n - 1) / 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

TEST(e0200, e0168) {
    ASSERT_EQ(S0168().convertToTitle(1), "A");
    ASSERT_EQ(S0168().convertToTitle(28), "AB");
    ASSERT_EQ(S0168().convertToTitle(701), "ZY");
}
