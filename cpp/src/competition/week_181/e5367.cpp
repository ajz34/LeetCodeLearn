// https://leetcode-cn.com/problems/longest-happy-prefix/

#include "extern.h"

class S5367 {
public:
    string longestPrefix(string s) {
        vector<int> lps(s.size(), 0);
        size_t i = 0, j = 1;
        while (j < s.size()) {
            if (s[i] == s[j]) lps[j++] = (i++) + 1;  // situ.1
            else if (i != 0) i = lps[i - 1];                   // situ.2
            else lps[j++] = 0;
        }
        return s.substr(0, lps.back());
    }
};

TEST(week181, e5367) {
    ASSERT_EQ(S5367().longestPrefix("level"), "l");
    ASSERT_EQ(S5367().longestPrefix("ababab"), "abab");
    ASSERT_EQ(S5367().longestPrefix("leetcodeleet"), "leet");
    ASSERT_EQ(S5367().longestPrefix("a"), "");
}

/* 发布题解：C++ 8 行无脑 KMP 与详解 LPS Table 构造过程，复杂度 O(n)
   https://leetcode-cn.com/problems/longest-happy-prefix/solution/c-8-xing-wu-nao-kmpfu-za-du-on-dai-geng-xin-by-ajz/
*/
