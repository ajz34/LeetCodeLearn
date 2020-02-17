// https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/

#include "extern.h"



class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};
        int word_len = words.front().size();
        // 1. generate word count map from `words`
        unordered_map<string, int> word_count;
        for (auto word : words) {
            auto pw = word_count.find(word);
            if (pw == word_count.cend()) word_count[word] = 1;
            else pw->second += 1;
        }
        vector<string> id_word; id_word.reserve(word_count.size());
        for (auto pw : word_count) id_word.push_back(pw.first);
        unordered_map<string, int> word_id;
        for (int i = 0; i < id_word.size(); ++i) word_id[id_word[i]] = i;
        vector<int> id_count(id_word.size());
        for (int i = 0; i < id_word.size(); ++i) id_count[i] = word_count[id_word[i]];

        vector<int> s_id(s.size(), -1);
        for (int i = 0; i <= int(s.size()) - word_len; ++i) {
            auto ps = word_id.find(s.substr(i, word_len));
            if (ps != word_id.cend()) s_id[i] = ps->second;
        }
        // 2. find possible solutions
        vector<int> result; vector<int> current_count(id_count.size(), 0);
        for (int i = 0; i < word_len; ++i) {
            for (int jo = 0; i + (jo + words.size()) * word_len <= s.size(); ) {  // operation on j will be defined later
                fill(current_count.begin(), current_count.end(), 0); bool to_try = true;
                for (int j = 0; j < words.size(); ++j) {
                    int id = s_id[i + (jo + j) * word_len];
                    if (id == -1) { to_try = false; jo += (j + 1); break; }
                    current_count[id] += 1;
                }
                if (!to_try) continue;
                if (equal(current_count.cbegin(), current_count.cend(), id_count.cbegin()))
                    result.push_back(i + jo * word_len);
                ++jo;
            }
        }
        return result;
    }
};

TEST(e0100, e0030) {
    vector<string> v{ "foo", "bar" };
    vector<int> res_vec = Solution().findSubstring("barfoothefoobarman", v);
    set<int> res = set<int>{ res_vec.begin(), res_vec.end() };
    set<int> ans = set<int>{ 0, 9 };
    ASSERT_THAT(res, ans);
    
    v = { "word","good","best","word" };
    res_vec = Solution().findSubstring("wordgoodgoodgoodbestword", v);
    res = set<int>{ res_vec.begin(), res_vec.end() };
    ans = set<int>{};
    ASSERT_THAT(res, ans);
}

/*  注释：这个程序的大体思路跟下述链接非常相似：
    https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-6/
    当然，我自己的做法里有些偷懒之处。所有 Hashmap 最后都将单词转为 ID 号码，并通过 ID 号进行一些向量的索引工作。
    因此，整个算法的复杂度仍然是 O(n * m)，其中 m 代表单词长度，n 代表待查找字符串长度。
*/