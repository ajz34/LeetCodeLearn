// https://leetcode-cn.com/problems/palindrome-partitioning/

#include "extern.h"

class S0131 {
    void partionInner(
        const vector<vector<int>>& stat,
        const string& s,
        vector<string>& vec,
        int idx,
        vector<vector<string>>& result) {
        if (idx == s.size()) {
            result.push_back(vec);
            return;
        }
        for (int r : stat[idx]) {
            vec.push_back(s.substr(idx, r - idx + 1));
            partionInner(stat, s, vec, r + 1, result);
            vec.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<int>> stat(s.size(), vector<int>{});
        for (int i = 0; i < s.size() * 2 - 1; ++i) {
            int l = i / 2, r = (i + 1) / 2;
            while (l >= 0 && r < s.size()) {
                if (s[l] != s[r]) break;
                stat[l].push_back(r);
                --l, ++r;
            }
        }
        vector<string> vec{};
        vector<vector<string>> result;
        partionInner(stat, s, vec, 0, result);
        return result;
    }
};

TEST(e0200, e0131) {
    auto res = S0131().partition("aab");
    vector<vector<string>> ans{ {"a", "a", "b"}, {"aa", "b"} };
    ASSERT_THAT(vec_to_set<vector<string>>(res), vec_to_set<vector<string>>(ans));
}
