// https://leetcode-cn.com/problems/repeated-dna-sequences/

#include "extern.h"

class S0187 {
public:
    int atcg_to_int(char c) {
        switch (c)
        {
        case 'A': return 0;
        case 'T': return 1;
        case 'C': return 2;
        case 'G': return 3;
        default:
            assert(false);
            return -1;
        }
    }
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return {};
        int val = 0;
        unordered_set<int> st; st.reserve(s.size() * 2);
        unordered_set<string> result;
        for (int i = 0; i < 10; ++i) {
            val *= 4;
            val += atcg_to_int(s[i]);
        }
        st.insert(val);
        for (int i = 10; i < s.size(); ++i) {
            val %= 262144;
            val *= 4;
            val += atcg_to_int(s[i]);
            if (st.find(val) != st.end())
                result.insert(s.substr(i - 9, 10));
            else
                st.insert(val);
        }
        return vector<string>{ result.begin(), result.end() };
    }
};

TEST(e0200, e0187) {
    vector<string> ans{ "AAAAACCCCC", "CCCCCAAAAA" };
    ASSERT_THAT(vec_to_set(S0187().findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT")), vec_to_set(ans));
}
