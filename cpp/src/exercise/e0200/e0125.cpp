// https://leetcode-cn.com/problems/valid-palindrome/

#include "extern.h"

class S0125 {
public:
    bool isPalindrome(string s) {
        string st;
        for (char c : s) {
            if (c >= 'a' && c <= 'z' || c >= '0' && c <= '9')
                st.push_back(c);
            else if (c >= 'A' && c <= 'Z')
                st.push_back(c + 32);
        }
        int il = 0, ir = st.size() - 1;
        while (il < ir)
            if (st[il++] != st[ir--]) return false;
        return true;
    }
};

TEST(e0200, e0125) {
    ASSERT_TRUE(S0125().isPalindrome("A man, a plan, a canal: Panama"));
    ASSERT_FALSE(S0125().isPalindrome("race a car"));
}
