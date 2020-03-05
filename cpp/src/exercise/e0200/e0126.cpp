// https://leetcode-cn.com/problems/word-ladder-ii/

#include "extern.h"

class S0126 {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.count(endWord) == 0) return {};
        unordered_set<string> begin;
        begin.insert(beginWord);
        unordered_set<string> end;
        end.insert(endWord);
        unordered_map<string, vector<string>> neighbors;
        if (!bfs(begin, end, neighbors, true, words)) return {};
        vector<vector<string>> ret;
        vector<string> path;
        dfs(neighbors, beginWord, endWord, ret, path);
        return ret;
    }

    bool bfs(unordered_set<string>& begin, unordered_set<string>& end, unordered_map<string, vector<string>>& neighbors,
        bool forward, unordered_set<string>& words) {
        if (begin.size() == 0) return false;
        for (string s : begin) words.erase(s);
        bool meet = false;
        unordered_set<string> next;
        for (string b : begin) {
            for (int n = 0; n < b.size(); n++) {
                string w = b;
                for (char i = 'a'; i <= 'z'; i++) {
                    w[n] = i;
                    if (!words.count(w)) continue;
                    next.insert(w);
                    string k = forward ? b : w;
                    string v = forward ? w : b;
                    if (!neighbors.count(k)) neighbors.insert(pair<string, vector<string>>(k, vector<string>()));
                    neighbors[k].push_back(v);
                    if (end.count(w)) meet = true;
                }
            }
        }
        if (meet) return true;
        if (next.size() > end.size()) return bfs(end, next, neighbors, !forward, words);
        return bfs(next, end, neighbors, forward, words);
    }

    void dfs(unordered_map<string, vector<string>>& neighbors, string& begin, string& end, vector<vector<string>>& ret, vector<string>& path) {
        if (ret.size() > 0 && path.size() == 0) return;
        path.push_back(begin);
        if (begin == end) {
            ret.emplace_back(path);
        }
        else if (neighbors.count(begin)) {
            for (string n : neighbors[begin])
                dfs(neighbors, n, end, ret, path);
        }
        path.erase(path.end() - 1);
    }
};

TEST(e0200, e0126) {
    string beginWord, endWord; vector<string> wordList;
    beginWord = "hit", endWord = "cog";
    wordList = { "hot", "dot", "dog", "lot", "log", "cog" };
    vector<vector<string>> ans, res;
    res = S0126().findLadders(beginWord, endWord, wordList);
    ans = {
        {"hit","hot","dot","dog","cog"},
        {"hit","hot","lot","log","cog"}
    };
    ASSERT_THAT(vec_to_set(res), vec_to_set(res));
}
