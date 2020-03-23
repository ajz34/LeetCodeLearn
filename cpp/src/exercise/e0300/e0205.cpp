// https://leetcode-cn.com/problems/isomorphic-strings/

#include "extern.h"

class S0205 {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> conv;
        unordered_set<char> pool;
        for (int i = 0; i < s.size(); ++i) {
            auto p = conv.find(s[i]);
            if (p == conv.end()) {
                conv[s[i]] = t[i];
                if (pool.find(t[i]) != pool.end()) return false;
                pool.insert(t[i]);
            }
            else if (p->second != t[i]) return false;
        }
        return true;
    }
};

TEST(e0300, e0205) {
    ASSERT_TRUE(S0205().isIsomorphic("egg", "add"));
    ASSERT_FALSE(S0205().isIsomorphic("foo", "bar"));
    ASSERT_TRUE(S0205().isIsomorphic("paper", "title"));
}
