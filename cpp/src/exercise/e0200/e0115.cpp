// https://leetcode-cn.com/problems/distinct-subsequences/

#include "extern.h"

class S0115 {
public:
    int numDistinct(string s, string t) {
        if (s.empty() || t.empty()) return 0;
        size_t t_size = t.size(), s_size = s.size();
        vector<vector<long long>> stat(t_size, vector<long long>(s_size, 0));
        for (size_t it = 0; it < t_size; ++it)
            for (size_t is = 0; is < s_size; ++is)
                if (s[is] == t[it]) stat[it][is] = 1;
        for (size_t it = t_size - 1; it-- > 0;) {
            long long t_sum = 0;
            for (size_t is = s_size; is-- > 0;) {
                if (stat[it][is] != 0) stat[it][is] = t_sum;
                t_sum += stat[it + 1][is];
            }
        }
        return accumulate(stat.front().cbegin(), stat.front().cend(), 0);
    }
};

TEST(e0200, e0115) {
    ASSERT_EQ(S0115().numDistinct("rabbbit", "rabbit"), 3);
    ASSERT_EQ(S0115().numDistinct("babgbag", "bag"), 5);
}
