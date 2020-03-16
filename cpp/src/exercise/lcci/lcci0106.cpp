// https://leetcode-cn.com/problems/compress-string-lcci/

// ºÄÊ±£º0:05:34
// ´íÎó´ÎÊý£º0

#include "extern.h"

class LCCI0106 {
public:
    string compressString(string S) {
        string result;
        char last_char = '\0';
        int cnt = 0;
        for (char c : S) {
            if (c == last_char) ++cnt;
            else {
                if (last_char != '\0') {
                    result.push_back(last_char);
                    result += to_string(cnt);
                }
                cnt = 1;
                last_char = c;
            }
        }
        if (last_char != '\0') {
            result.push_back(last_char);
            result += to_string(cnt);
        }
        return (result.size() < S.size()) ? result : S;
    }
};

TEST(lcci, lcci0106) {
    ASSERT_EQ(LCCI0106().compressString("a2b1c5a3"), "a2b1c5a3");
    ASSERT_EQ(LCCI0106().compressString("abbccd"), "abbccd");
}
