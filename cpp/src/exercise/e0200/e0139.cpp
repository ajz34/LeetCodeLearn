// https://leetcode-cn.com/problems/word-break/

#include "extern.h"

class S0139 {
    bool wordBreakInner(string s, int l, const map<int, unordered_set<string>>& dict, vector<bool>& stat) {
        if (l == s.size()) return true;
        if (!stat[l]) return false;
        for (auto p : dict) {
            if (l + p.first > s.size()) break;
            if (l + p.first < s.size() && !stat[l + p.first]) continue;
            if (p.second.find(s.substr(l, p.first)) != p.second.end())
                if (wordBreakInner(s, l + p.first, dict, stat)) return true;
        }
        stat[l] = false;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<int, unordered_set<string>> dict;
        for (auto word : wordDict)
            dict[word.size()].insert(word);
        vector<bool> stat(s.size(), true);
        return wordBreakInner(s, 0, dict, stat);
    }
};

TEST(e0200, e0139) {
    string s; vector<string> wordDict;
    s = "leetcode", wordDict = { "leet", "code" };
    ASSERT_TRUE(S0139().wordBreak(s, wordDict));
    s = "applepenapple", wordDict = { "apple", "pen" };
    ASSERT_TRUE(S0139().wordBreak(s, wordDict));
    s = "catsandog", wordDict = { "cats", "dog", "sand", "and", "cat" };
    ASSERT_FALSE(S0139().wordBreak(s, wordDict));
}
