#include "extern.h"

class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        // 01234567 Line 0
        // ababcab
        // 2356777  Line 1
        // 3322321  Line 1 - Line 0
        // 3322321 v[i] = min(v[i + 1] + 1, v[i]); then find maximum
        if (s.empty()) return 0;
        auto v = vector<int>(s.size(), 0);
        auto d = unordered_map<char, int>();
        for (int i = 0; i < s.size(); ++i) {
            auto k = d.find(s[i]);  // k->second = d[s[i]]
            if (k != d.end()) v[k->second] = i - k->second;
            v[i] = s.size() - i;
            d[s[i]] = i;
        }
        for (int i = int(v.size()) - 2; i >= 0; --i)
            v[i] = min(v[i + 1] + 1, v[i]);
        return *max_element(v.cbegin(), v.cend());
    }
};

TEST(e0100, e0003) {
    ASSERT_EQ(Solution().lengthOfLongestSubstring("abcabcbb"), 3);
    ASSERT_EQ(Solution().lengthOfLongestSubstring("bbbbb"), 1);
    ASSERT_EQ(Solution().lengthOfLongestSubstring("pwwkew"), 3);
    ASSERT_EQ(Solution().lengthOfLongestSubstring(""), 0);
}
