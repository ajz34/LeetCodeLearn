// https://leetcode-cn.com/problems/longest-palindrome/

#include "extern.h"

class S0409 {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for (char c : s) mp[c] += 1;
        int result = 0;
        bool has_odd = false;
        for (auto& p : mp) {
            if (p.second % 2 == 0) result += p.second;
            else {
                result += p.second - 1;
                has_odd = true;
            }
        }
        return result + (has_odd ? 1 : 0);
    }
};

TEST(e0500, e0409) {
    ASSERT_EQ(S0409().longestPalindrome("abccccdd"), 7);
}
