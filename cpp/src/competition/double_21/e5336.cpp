// https://leetcode-cn.com/problems/increasing-decreasing-string/

#include "extern.h"

class S5336 {
public:
    string sortString(string s) {
        if (s.empty()) return s;
        map<char, int> word;
        for (char c : s) word[c] += 1;
        string result = "";
        while (!word.empty()) {
            unordered_set<char> delete_idx;
            // forward
            for (auto p = word.begin(); p != word.end(); ++p) {
                if (p->second != 0) {
                    result.push_back(p->first);
                    p->second -= 1;
                    if (p->second == 0) delete_idx.insert(p->first);
                }
            }
            // backward
            for (auto p = word.rbegin(); p != word.rend(); ++p) {
                if (p->second != 0) {
                    result.push_back(p->first);
                    p->second -= 1;
                    if (p->second == 0) delete_idx.insert(p->first);
                }
            }
            for (auto c : delete_idx)
                word.erase(c);
        }
        return result;
    }
};

TEST(double21, e5336) {
    ASSERT_EQ(S5336().sortString("aaaabbbbcccc"), "abccbaabccba");
    ASSERT_EQ(S5336().sortString("rat"), "art");
    ASSERT_EQ(S5336().sortString("leetcode"), "cdelotee");
    ASSERT_EQ(S5336().sortString("ggggggg"), "ggggggg");
    ASSERT_EQ(S5336().sortString("spo"), "ops");
}
