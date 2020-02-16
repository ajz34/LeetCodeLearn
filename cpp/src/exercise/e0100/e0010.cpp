#include "extern.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        // TODO: Low Efficiency
        // recursive: success condition
        if (p.empty()) return s.empty();
        if (p.size() == 1) return (s.size() == 1 && (p[0] == '.' || s[0] == p[0]));
        // assert p.size() >= 2, second char != or == '*'
        if (p[1] != '*')
            return !s.empty() && (p[0] == '.' || s[0] == p[0]) && isMatch(s.substr(1), p.substr(1));
        else {
            // zero char same
            if (isMatch(s, p.substr(2))) return true;
            // one or more char same
            while (p[0] == '.' || s[0] == p[0]) {
                if (s.empty()) return false;
                s = s.substr(1);
                if (isMatch(s, p.substr(2))) return true;
            }
        }
        return false;  // should not exec this line, only suppress ide warning
    }
};

TEST(e0100, e0010) {
    ASSERT_FALSE(Solution().isMatch("aa", "a"));
    ASSERT_TRUE(Solution().isMatch("aa", "a*"));
    ASSERT_TRUE(Solution().isMatch("ab", ".*"));
    ASSERT_TRUE(Solution().isMatch("aab", "c*a*b"));
    ASSERT_FALSE(Solution().isMatch("mississippi", "mis*is*p*."));
    ASSERT_TRUE(Solution().isMatch("mississippi", "mis*is*ip*."));
    ASSERT_FALSE(Solution().isMatch("ab", ".*c"));
    ASSERT_TRUE(Solution().isMatch("a", "ab*"));
    ASSERT_TRUE(Solution().isMatch("", "c*c*"));
    ASSERT_FALSE(Solution().isMatch("a", "..a"));
}
