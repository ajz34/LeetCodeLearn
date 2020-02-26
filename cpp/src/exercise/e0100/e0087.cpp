// https://leetcode-cn.com/problems/scramble-string/

#include "extern.h"

class S0087 {
public:
    bool isScramble(string s1, string s2) {
        assert(s1.size() == s2.size());
        assert(!s1.empty());
        if (s1.size() == 1) return s1 == s2;
        if (s1.size() == 2) return s1 == s2 || (s1[1] == s2[0] && s1[0] == s2[1]);

        unordered_map<char, int> mp_front;
        for (auto c1 : s1) mp_front[c1] = 0;
        unordered_map<char, int> mp_back{ mp_front };
        for (int i = 0; i < s1.size() - 1; ++i) {
            mp_front[s1[i]] += 1;
            mp_back[s1[i]] += 1;
            mp_front[s2[i]] -= 1;
            mp_back[s2[s2.size() - i - 1]] -= 1;
            bool test_front = true, test_back = true;
            for (auto p : mp_front) {
                if (p.second != 0) {
                    test_front = false;
                    break;
                }
            }
            for (auto p : mp_back) {
                if (p.second != 0) {
                    test_back = false;
                    break;
                }
            }
            if (test_front &&
                isScramble(s1.substr(0, i + 1), s2.substr(0, i + 1)) &&
                isScramble(s1.substr(i + 1), s2.substr(i + 1))) return true;
            if (test_back &&
                isScramble(s1.substr(0, i + 1), s2.substr(s1.size() - 1 - i)) &&
                isScramble(s1.substr(i + 1), s2.substr(0, s1.size() - 1 - i))) return true;
        }
        return false;
    }
};

TEST(e0100, e0087) {
    ASSERT_TRUE(S0087().isScramble("great", "rgtae"));
    ASSERT_TRUE(S0087().isScramble("great", "rgeat"));
    ASSERT_FALSE(S0087().isScramble("abcde", "caebd"));
}
