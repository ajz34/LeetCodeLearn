#include "extern.h"

class Solution {
public:
    int myAtoi(string str) {
        // 1. trim left
        int i = 0;
        for (i = 0; i < str.size(); ++i)
            if (str[i] != ' ') break;
        str = str.substr(i, str.size() - i);
        // 2. find first non-number character
        int sgn = 1; int sgn_char = 0;
        for (i = 0; i < str.size(); ++i) {
            if (i == 0 && (str[0] == '-' || str[0] == '+')) {
                sgn_char = 1;
                sgn = str[i] == '-' ? -1 : 1;
                continue; }
            if ('0' <= str[i] && str[i] <= '9') continue;
            break;
        }
        str = str.substr(sgn_char, size_t(i) + 1 - sgn_char);
        // 3. trim left zeros
        for (i = 0; i < str.size(); ++i)
            if (str[i] != '0') break;
        str = str.substr(i, str.size() - i);
        // 4. exclude zero character
        if (str.empty()) return 0;
        // 5. exclude digit number > 12
        if (str.size() > 12) return sgn < 0 ? -2147483648 : 2147483647;
        // 6. first atol, then ltoi
        long long l = atoll(str.c_str()) * sgn;
        if (l > 2147483647) return 2147483647;
        else if (l < -2147483647) return -2147483648;
        else return int(l);
    }
};

TEST(e0100, e0008) {
    auto a = Solution().myAtoi("42");
    ASSERT_EQ(Solution().myAtoi("42"), 42);
    ASSERT_EQ(Solution().myAtoi("   -42"), -42);
    ASSERT_EQ(Solution().myAtoi("4193 with words"), 4193);
    ASSERT_EQ(Solution().myAtoi("words and 987"), 0);
    ASSERT_EQ(Solution().myAtoi("-91283472332"), -2147483648);
    ASSERT_EQ(Solution().myAtoi("  0000000000012345678"), 12345678);
    ASSERT_EQ(Solution().myAtoi("000000000000000000"), 0);
    ASSERT_EQ(Solution().myAtoi("+"), 0);
    ASSERT_EQ(Solution().myAtoi("20000000000000000000"), 2147483647);
}
