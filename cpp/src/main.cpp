#include "extern.h"

class Solution {
    bool wordBreakInner(const string& s, int l,
                        vector<int>& split, vector<vector<int>>& split_list,
                        unordered_map<int, unordered_set<string>>& dict,
                        vector<string>& result) {
        bool success = false;
        if (l == s.size()) {
            string res;
            for (int i = 0; i < split.size() - 1; ++i) {
                if (i != 0) res += " ";
                res += s.substr(split[i], split[i + 1] - split[i]);
            }
            result.push_back(res);
            return true;
        }
        if (split_list[l].empty()) {
            for (auto& p : dict) {
                if (l + p.first > s.size()) continue;
                if (p.second.find(s.substr(l, p.first)) != p.second.end())
                    split_list[l].push_back(l + p.first);
            }
            if (split_list[l].empty())
                split_list[l].push_back(-1);
        }
        if (split_list[l][0] == -1)
            return false;
        for (int i : split_list[l]) {
            split.push_back(i);
            if (wordBreakInner(s, i, split, split_list, dict, result))
                success = true;
            split.pop_back();
        }
        if (!success) split_list[l] = { -1 };
        return success;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, unordered_set<string>> dict;
        for (auto& word : wordDict)
            dict[word.size()].insert(word);
        vector<int> split{ 0 };
        vector<vector<int>> split_list(s.size(), vector<int>{});
        vector<string> result;
        wordBreakInner(s, 0, split, split_list, dict, result);
        return result;
    }
};

int main() {
    string s; vector<string> wordDict;
    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", wordDict = { "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa" };
    cout << Solution().wordBreak(s, wordDict).size() << endl;
    s = "catsanddog", wordDict = { "cat", "cats", "and", "sand", "dog" };
    cout << Solution().wordBreak(s, wordDict) << endl;
    s = "pineapplepenapple", wordDict = { "apple", "pen", "applepen", "pine", "pineapple" };
    cout << Solution().wordBreak(s, wordDict) << endl;
    s = "catsandog", wordDict = { "cats", "dog", "sand", "and", "cat" };
    cout << Solution().wordBreak(s, wordDict) << endl;
}
