// https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters/

#include "extern.h"

class S1160 {
    void word_to_vec(string& word, vector<short>& vec) {
        fill(vec.begin(), vec.end(), 0);
        for (auto c : word)
            vec[c - 'a'] += 1;
    }
    bool word_larger(const vector<short>& v1, const vector<short>& v2) {
        for (int i = 0; i < 26; ++i)
            if (v1[i] < v2[i]) return false;
        return true;
    }
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<short> vec_chars(26, 0), vec_word(26, 0);
        word_to_vec(chars, vec_chars);
        int result = 0;
        for (auto& word : words) {
            word_to_vec(word, vec_word);
            if (word_larger(vec_chars, vec_word))
                result += word.size();
        }
        return result;
    }
};

TEST(e1200, e1160) {
    vector<string> words; string chars;
    words = { "cat", "bt", "hat", "tree" }, chars = "atach";
    ASSERT_EQ(S1160().countCharacters(words, chars), 6);
    words = { "hello", "world", "leetcode" }, chars = "welldonehoneyr";
    ASSERT_EQ(S1160().countCharacters(words, chars), 10);
}
