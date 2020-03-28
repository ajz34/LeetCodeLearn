// https://leetcode-cn.com/problems/short-encoding-of-words/

#include "extern.h"

class S0820 {
    struct CompareWords {
        inline bool operator()(const string& s1, const string& s2) const {
            if (s1.size() != s2.size()) return s1.size() > s2.size();
            else return s1 > s2;
        }
    };
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), CompareWords());
        set<string> st;
        for (auto& word_ : words) {
            string word; word.resize(word_.size());
            reverse_copy(word_.begin(), word_.end(), word.begin());
            if (st.empty()) { st.insert(word); continue; }
            auto p = st.upper_bound(word);
            if (p == st.end() || word != (*p).substr(0, word.size()))
                st.insert(word);
        }
        int result = 0;
        for (auto& word : st) result += word.size() + 1;
        return result;
    }
};

TEST(e0900, e0820) {
    vector<string> words;
    words = { "time", "me", "bell" };
    ASSERT_EQ(S0820().minimumLengthEncoding(words), 10);
}
