// https://leetcode-cn.com/problems/word-break-ii/

#include "extern.h"

class S0140 {
    bool wordBreakInner(const string& s, int l,
        vector<int>& split, vector<unordered_set<int>>& split_list,
        unordered_map<int, unordered_set<string>>& dict,
        vector<string>& result) {
        bool success = false;
        // �����������򷵻��б�����ӽ��
        if (l == s.size()) {
            string res;
            for (int i = 0; i < split.size() - 1; ++i) {
                if (i != 0) res += " ";
                res += s.substr(split[i], split[i + 1] - split[i]);
            }
            result.push_back(res);
            return true;
        }
        // ������ l ����ĸ�ж��ٿ����ж����ֺ��ʵĵ��ʵ��б� split_list[l]
        if (split_list[l].empty()) {
            for (auto& p : dict) {
                if (l + p.first > s.size()) continue;
                if (p.second.find(s.substr(l, p.first)) != p.second.end())
                    split_list[l].insert(l + p.first);
            }
            if (split_list[l].empty())
                split_list[l].insert(-1);
        }
        // ���Ƕ��壬���û�к��ʵ��б���ô split_list[l] = { -1 }������֪�����ܲ��ø�ֵ
        if (*split_list[l].begin() == -1)
            return false;
        // ������ÿ�α�������ʱ�����ò������н���ĵ����ų���
        vector<int> delete_idx;
        for (int i : split_list[l]) {
            split.push_back(i);
            if (wordBreakInner(s, i, split, split_list, dict, result))
                success = true;
            else
                delete_idx.push_back(i);
            split.pop_back();
        }
        if (!success)
            split_list[l] = { -1 };
        else for (auto idx : delete_idx)
            split_list[l].erase(idx);
        return success;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, unordered_set<string>> dict;
        for (auto& word : wordDict)
            dict[word.size()].insert(word);
        vector<int> split{ 0 };
        vector<unordered_set<int>> split_list(s.size(), unordered_set<int>{});
        vector<string> result;
        wordBreakInner(s, 0, split, split_list, dict, result);
        return result;
    }
};

TEST(e0200, e0140) {
    string s; vector<string> wordDict; vector<string> ans;
    s = "catsanddog", wordDict = { "cat", "cats", "and", "sand", "dog" };
    ans = { "cats and dog", "cat sand dog" };
    ASSERT_THAT(vec_to_set<string>(S0140().wordBreak(s, wordDict)), vec_to_set<string>(ans));
    s = "pineapplepenapple", wordDict = { "apple", "pen", "applepen", "pine", "pineapple" };
    ans = { "pine apple pen apple", "pineapple pen apple", "pine applepen apple" };
    ASSERT_THAT(vec_to_set<string>(S0140().wordBreak(s, wordDict)), vec_to_set<string>(ans));
    s = "catsandog", wordDict = { "cats", "dog", "sand", "and", "cat" };
    ans = {};
    ASSERT_THAT(vec_to_set<string>(S0140().wordBreak(s, wordDict)), vec_to_set<string>(ans));
}
