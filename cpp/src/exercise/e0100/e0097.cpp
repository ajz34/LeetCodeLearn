// https://leetcode-cn.com/problems/interleaving-string/

#include "extern.h"

class Solution {
public:
    bool isInterleave(const string& s1, const string& s2, const string& s3) {
        // https://leetcode-cn.com/problems/interleaving-string/solution/jiao-cuo-zi-fu-chuan-by-leetcode/
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<bool>> stat(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        for (size_t i1 = 0; i1 < s1.size() + 1; ++i1) {
            for (size_t i2 = 0; i2 < s2.size() + 1; ++i2) {
                if (i1 == 0 && i2 == 0)
                    stat[0][0] = true;
                else if (i1 == 0)
                    stat[0][i2] = (s2[i2 - 1] == s3[i1 + i2 - 1]) && stat[0][i2 - 1];
                else if (i2 == 0)
                    stat[i1][0] = (s1[i1 - 1] == s3[i1 + i2 - 1]) && stat[i1 - 1][0];
                else
                    stat[i1][i2] = ((s2[i2 - 1] == s3[i1 + i2 - 1]) && stat[i1][i2 - 1]) || ((s1[i1 - 1] == s3[i1 + i2 - 1]) && stat[i1 - 1][i2]);
            }
        }
        return stat[s1.size()][s2.size()];
    }
};

TEST(e0100, e0097) {
    ASSERT_TRUE(Solution().isInterleave("aabcc", "dbbca", "aadbbcbacc"));
    ASSERT_FALSE(Solution().isInterleave("aabcc", "dbbca", "aadbbbaccc"));
}
