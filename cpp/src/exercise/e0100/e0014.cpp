#include "extern.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int i = -1;
        while (true) {
            ++i;
            if (strs[0].size() <= i) break;
            char c = strs[0][i]; bool success = true;
            for (auto& str : strs)
                if (str.size() <= i || str[i] != c) {
                    success = false;
                    break;
                }
            if (!success) break;
        }
        return strs[0].substr(0, i);
    }
};

TEST(e0100, e0014) {
    vector<string> v{ "flower", "flow", "flight" };
    ASSERT_EQ(Solution().longestCommonPrefix(v), "fl");
    vector<string> l{ "dog", "racecar", "car" };
    ASSERT_EQ(Solution().longestCommonPrefix(l), "");
}
