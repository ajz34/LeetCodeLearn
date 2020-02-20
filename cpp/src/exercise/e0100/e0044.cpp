// https://leetcode-cn.com/problems/wildcard-matching/

#include "extern.h"

class Solution {
public:
    bool isSameNaive(string s, string p) {
        assert(s.size() == p.size());
        for (size_t i = 0; i < s.size(); ++i)
            if (p[i] != '?' && s[i] != p[i]) return false;
        return true;
    }

    bool isMatch_0044(string s, string p) {
        // extreme condition
        if (p.empty()) return s.empty();

        size_t pl = 0, pr = 0, ps = 0;
        while (pr < p.size()) {
            // find next non-* char
            while (pl < p.size() && p[pl] == '*') ++pl;
            pr = pl; if (pl == p.size()) return true;
            while (pr < p.size() && p[pr] != '*') ++pr;
            if (ps + (pr - pl) > s.size()) return false;
            // pr is the last one
            if (pl != 0 && pr == p.size())
                return isSameNaive(s.substr(s.size() - (pr - pl), pr - pl), p.substr(pl, pr - pl));
            if (pl == 0) {
                if (!isSameNaive(s.substr(ps, pr - pl), p.substr(pl, pr - pl))) return false;
                ps += (pr - pl);
                pl = pr;
            }
            // pr is not the last one
            for (; ps + (pr - pl) <= s.size(); ++ps)
                if (isSameNaive(s.substr(ps, pr - pl), p.substr(pl, pr - pl))) {
                    ps += (pr - pl);
                    pl = pr;
                    break;
                }
            if (ps + (pr - pl) > s.size()) return false;
        }
        return ps == s.size();
    }
};

TEST(e0100, e0044) {
    // special case that `isMatch` is the same with e0010
    ASSERT_FALSE(Solution().isMatch_0044("aa", "a"));
    ASSERT_TRUE(Solution().isMatch_0044("aa", "*"));
    ASSERT_FALSE(Solution().isMatch_0044("cb", "?a"));
    ASSERT_TRUE(Solution().isMatch_0044("adceb", "*a*b"));
    ASSERT_FALSE(Solution().isMatch_0044("acdcb", "a*c?b"));
}
