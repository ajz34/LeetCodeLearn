// https://leetcode-cn.com/problems/count-and-say/

#include "extern.h"

class Solution {
public:
    string countAndSay(int n) {
        string st = "1", sr = "1";
        for (; n != 1; --n) {
            int cnt = 0; char t = '\0';
            st = "";
            for (const char& c : sr) {
                if (c == t) { ++cnt; continue; }
                if (cnt != 0) { st += cnt + '0'; st += t; }
                t = c;
                cnt = 1;
            }
            st += cnt + '0'; st += t;
            sr = st;
        }
        return sr;
    }
};

TEST(e0100, e0038) {
    ASSERT_EQ(Solution().countAndSay(1), "1");
    ASSERT_EQ(Solution().countAndSay(2), "11");
    ASSERT_EQ(Solution().countAndSay(3), "21");
    ASSERT_EQ(Solution().countAndSay(4), "1211");
    ASSERT_EQ(Solution().countAndSay(5), "111221");
}
