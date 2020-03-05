// https://leetcode-cn.com/problems/word-ladder-ii/

#include "extern.h"

class S0126 {

    bool is_diff1(const string& s1, const string& s2) {
        assert(s1.size() == s2.size());
        int dif = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i])
                if (dif++ >= 1) return false;
        }
        return dif == 1;
    }

    void bfs_process(
        unordered_set<int>& lst_valid,
        unordered_set<int>& lst_bfs_layer,
        unordered_map<int, vector<vector<int>>>& res_bfs,
        const vector<string>& wordList) {

        unordered_map<int, unordered_set<int>> lst_map;
        unordered_set<int> lst_next_layer;

        for (auto idx_bfs : lst_bfs_layer) {
            for (auto idx_next : lst_valid)
                if (is_diff1(wordList[idx_bfs], wordList[idx_next])) {
                    lst_map[idx_bfs].insert(idx_next);
                    lst_next_layer.insert(idx_next);
                }
        }

        for (auto idx_next : lst_next_layer)
            lst_valid.erase(idx_next);

        unordered_map<int, vector<vector<int>>> res_next;
        for (auto p : res_bfs) {
            for (auto& v : p.second) {
                for (auto idx : lst_map[p.first]) {
                    res_next[idx].push_back(v);
                    res_next[idx].back().push_back(idx);
                }
            }
        }

        swap(lst_bfs_layer, lst_next_layer);
        swap(res_bfs, res_next);
    }

    bool is_interset_empty(unordered_set<int>& s1, unordered_set<int>& s2) {
        unordered_set<int>* pl = (s1.size() < s2.size() ? &s1 : &s2);
        unordered_set<int>* pu = (s1.size() < s2.size() ? &s2 : &s1);
        for (auto v : *pl)
            if (pu->find(v) != pu->end()) return false;
        return true;
    }

    vector<vector<int>> concate_res(
        const unordered_map<int, vector<vector<int>>>& res_top,
        const unordered_map<int, vector<vector<int>>>& res_bot) {

        vector<vector<int>> result;
        for (auto& pt : res_top) {
            if (res_bot.find(pt.first) == res_bot.end()) continue;
            for (auto& vb : res_bot.at(pt.first)) {
                for (auto& vt : pt.second) {
                    vector<int> v{ vt };
                    for (int i = vb.size() - 1; i-- > 0;)
                        v.push_back(vb[i]);
                    result.push_back(v);
                }
            }
        }
        return result;
    }

    template<class T>
    vector<vector<T>> matrix_mapping(const vector<vector<int>>& mat, const vector<T>& lst) {
        vector<vector<T>> result;
        for (auto& v : mat) {
            result.push_back({});
            vector<T>& rb = result.back();
            for (auto& i : v)
                rb.push_back(lst[i]);
        }
        return result;
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        auto p_end_word = find(wordList.begin(), wordList.end(), endWord);
        if (p_end_word == wordList.end()) return {};
        int idx_end_word = p_end_word - wordList.begin();
        wordList.push_back(beginWord);
        int s_size = wordList.size();
        int idx_begin_word = s_size - 1;

        unordered_set<int> valid_lst;
        for (int i = 0; i < s_size; ++i)
            valid_lst.insert(i);

        unordered_set<int> lst_top_layer{ idx_begin_word }, lst_bot_layer{ idx_end_word };
        unordered_set<int> lst_top_valid{ valid_lst }, lst_bot_valid{ valid_lst };
        unordered_map<int, vector<vector<int>>> res_top, res_bot;
        res_top[idx_begin_word] = { { idx_begin_word } };
        res_bot[idx_end_word] = { { idx_end_word } };
        lst_top_valid.erase(idx_begin_word);
        lst_bot_valid.erase(idx_end_word);

        while (true) {
            bfs_process(lst_top_valid, lst_top_layer, res_top, wordList);
            if (!is_interset_empty(lst_top_layer, lst_bot_layer)) break;
            bfs_process(lst_bot_valid, lst_bot_layer, res_bot, wordList);
            if (!is_interset_empty(lst_top_layer, lst_bot_layer)) break;
            if (lst_top_layer.empty() || lst_bot_layer.empty()) return {};
        }

        vector<vector<int>> result_idx = concate_res(res_top, res_bot);
        return matrix_mapping<string>(result_idx, wordList);
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
