// https://leetcode-cn.com/problems/minimum-window-substring/

#include "extern.h"

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) return "";

        unordered_map<char, int> t_stat{};
        for (char c : t) t_stat[c] += 1;
        unordered_map<char, int> s_stat{};
        for (auto p : t_stat) s_stat[p.first] = 0;
        unordered_set<char> s_lack;
        for (auto p : t_stat) s_lack.insert(p.first);

        auto pl = s.cbegin(), pr = s.cbegin();
        int min_length = s.size() + 1;
        auto min_pl = pl, min_pr = pr;
        auto update_min = [&s_lack, &min_length, &min_pl, &min_pr, &pl, &pr]() {
            if (s_lack.empty() && int(pr - pl) < min_length) {
                min_length = int(pr - pl);
                min_pl = pl; min_pr = pr;
            }
        };
        while (true) {
            if (s_lack.empty()) {
                if (s_stat.find(*pl) != s_stat.cend()) {
                    s_stat[*pl] -= 1;
                    if (s_stat[*pl] < t_stat[*pl]) s_lack.insert(*pl);
                }
                ++pl;
                update_min();
            }
            else {
                if (pr == s.cend()) break;
                if (s_stat.find(*pr) != s_stat.cend()) {
                    s_stat[*pr] += 1;
                    if (s_stat[*pr] >= t_stat[*pr]) s_lack.erase(*pr);
                }
                ++pr;
                update_min();
            }
            if (min_length == t.size()) return string(min_pl, min_pr);
        }

        if (min_length > s.size()) return "";
        return string(min_pl, min_pr);
    }
};

TEST(e0100, e0076) {
    ASSERT_EQ(Solution().minWindow("ADOBECODEBANC", "ABC"), "BANC");
}
