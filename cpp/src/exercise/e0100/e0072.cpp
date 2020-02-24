// https://leetcode-cn.com/problems/edit-distance/

#include "extern.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int s1 = word1.size(), s2 = word2.size();
        if (s1 * s2 == 0) return max(s1, s2);
        vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, 0));
        for (int i = 0; i < s1 + 1; ++i) dp[i][0] = i;
        for (int i = 0; i < s2 + 1; ++i) dp[0][i] = i;
        for (int i = 1; i < s1 + 1; ++i) {
            for (int j = 1; j < s2 + 1; ++j) {
                int min_path = 2147483647;
                min_path = min(dp[i - 1][j - 1] - (word1[i - 1] == word2[j - 1] ? 1 : 0), min_path);
                min_path = min(dp[i - 1][j], min_path);
                min_path = min(dp[i][j - 1], min_path);
                dp[i][j] = min_path + 1;
            }
        }
        return dp[s1][s2];
    }
};

TEST(e0100, e0072) {
    ASSERT_EQ(Solution().minDistance("horse", "ros"), 3);
    ASSERT_EQ(Solution().minDistance("intention", "execution"), 5);
}
