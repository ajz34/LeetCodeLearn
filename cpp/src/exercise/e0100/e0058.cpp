// https://leetcode-cn.com/problems/length-of-last-word/

#include "extern.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        auto pl = s.crbegin(), pr = pl;
        while (pr != s.crend() && *pr == ' ') ++pr; pl = pr;
        while (pl != s.crend() && *pl != ' ') ++pl;
        return int(pl - pr);
    }
};

TEST(e0100, e0058) {
    ASSERT_EQ(Solution().lengthOfLastWord("Hello World"), 5);
}
