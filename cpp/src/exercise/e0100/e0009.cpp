#include "extern.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        int x_ = x;
        string s{};
        s.reserve(32);
        while (x_ > 0) {
            s.push_back(x_ % 10 + '0');
            x_ /= 10;
        }
        return atoi(s.c_str()) == x;
    }
};

TEST(e0100, e0009) {
    ASSERT_TRUE(Solution().isPalindrome(121));
    ASSERT_FALSE(Solution().isPalindrome(-121));
    ASSERT_FALSE(Solution().isPalindrome(10));
}
