// https://leetcode-cn.com/problems/word-ladder/

#include "extern.h"

class S0127 {

    bool is_diff1(const string& s1, const string& s2) {
        assert(s1.size() == s2.size());
        int dif = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                ++dif;
                if (dif > 1) return false;
            }
        }
        return dif == 1;
    }

    template<class T>
    bool is_interset_empty(unordered_set<T>& s1, unordered_set<T>& s2) {
        unordered_set<T>* pl = (s1.size() < s2.size() ? &s1 : &s2);
        unordered_set<T>* pu = (s1.size() < s2.size() ? &s2 : &s1);
        for (auto v : *pl)
            if (pu->find(v) != pu->end()) return false;
        return true;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto p_end_word = find(wordList.begin(), wordList.end(), endWord);
        if (p_end_word == wordList.end()) return {};
        int idx_end_word = p_end_word - wordList.begin();
        wordList.push_back(beginWord);
        int idx_begin_word = wordList.size() - 1;

        unordered_set<string> word_top_excluded{ wordList.begin(), wordList.end() };
        unordered_set<string> word_bot_excluded{ word_top_excluded };
        word_top_excluded.erase(beginWord);
        word_bot_excluded.erase(endWord);

        int result = 1;
        unordered_set<string> word_top_cur, word_top_prev;
        word_top_prev.insert(beginWord);
        unordered_set<string> word_bot_cur, word_bot_prev;
        word_bot_prev.insert(endWord);

        auto bfs_step = [&result, this](unordered_set<string>& word_prev, unordered_set<string>& word_cur, unordered_set<string>& word_excluded) {
            word_cur.clear();
            for (auto s_prev : word_prev) {
                for (int i = 0; i < s_prev.size(); ++i) {
                    int c_tmp = s_prev[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        s_prev[i] = c;
                        if (word_excluded.find(s_prev) != word_excluded.end())
                            word_cur.insert(s_prev);
                    }
                    s_prev[i] = c_tmp;
                }
            }
            for (auto& s_cur : word_cur)
                word_excluded.erase(s_cur);
            swap(word_prev, word_cur);
            result += 1;
        };

        while (!word_top_prev.empty() && !word_bot_prev.empty()) {
            bfs_step(word_top_prev, word_top_cur, word_top_excluded);
            if (!is_interset_empty(word_top_prev, word_bot_prev)) break;
            bfs_step(word_bot_prev, word_bot_cur, word_bot_excluded);
            if (!is_interset_empty(word_top_prev, word_bot_prev)) break;
        }
        return (word_top_prev.empty() || word_bot_prev.empty()) ? 0 : result;
    }

    int ladderLength_others(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(begin(wordList), end(wordList));
        if (!wordSet.count(endWord)) return 0;

        unordered_set<string> from{ beginWord };
        unordered_set<string> to{ endWord };
        int res = 1;
        while (!from.empty())
        {
            ++res;
            unordered_set<string> tmp;
            for (auto& x : from) wordSet.erase(x);
            for (auto& x : from)
            {
                for (int i = 0; i < x.size(); ++i)
                {
                    string s = x;
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        s[i] = c;
                        if (wordSet.count(s))
                        {
                            if (to.count(s)) return res;
                            tmp.emplace(s);
                        }
                    }
                }
            }
            if (tmp.size() < to.size())
            {
                from = tmp;
            }
            else
            {
                from = to;
                to = tmp;
            }
        }
        return 0;
    }
};

TEST(e0200, e0127) {
    string beginWord, endWord;
    vector<string> wordList;
    beginWord = "hit", endWord = "cog";
    wordList = { "hot", "dot", "dog", "lot", "log", "cog" };
    ASSERT_EQ(S0127().ladderLength(beginWord, endWord, wordList), 5);
}
