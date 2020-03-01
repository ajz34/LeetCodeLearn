// https://leetcode-cn.com/problems/rank-teams-by-votes/

#include "extern.h"

class S5345 {
    struct ComaprePair {
        inline bool operator()(pair<char, vector<int>>& p1, pair<char, vector<int>>& p2) {
            bool result = false;
            for (int i = 0; i < p1.second.size(); ++i)
                if (p1.second[i] != p2.second[i]) return p1.second[i] > p2.second[i];
            return p1.first < p2.first;
        }
    };
public:
    string rankTeams(vector<string>& votes) {
        if (votes.empty()) return {};
        unordered_map<char, vector<int>> mp;
        for (auto c : votes.front()) mp[c] = vector<int>(votes.front().size(), 0);
        for (auto& s : votes) {
            for (int i = 0; i < s.size(); ++i)
                mp[s[i]][i] += 1;
        }
        vector<pair<char, vector<int>>> res_p(mp.begin(), mp.end());
        sort(res_p.begin(), res_p.end(), ComaprePair());
        string result;
        for (auto& p : res_p) result.push_back(p.first);
        return result;
    }
};

TEST(week178, e5345) {
    vector<string> votes;
    votes = { "ABC","ACB","ABC","ACB","ACB" };
    ASSERT_EQ(S5345().rankTeams(votes), "ACB");
    votes = { "WXYZ","XYZW" };
    ASSERT_EQ(S5345().rankTeams(votes), "XWYZ");
    votes = { "ZMNAGUEDSJYLBOPHRQICWFXTVK" };
    ASSERT_EQ(S5345().rankTeams(votes), "ZMNAGUEDSJYLBOPHRQICWFXTVK");
    votes = { "BCA","CAB","CBA","ABC","ACB","BAC" };
    ASSERT_EQ(S5345().rankTeams(votes), "ABC");
    votes = { "M","M","M","M" };
    ASSERT_EQ(S5345().rankTeams(votes), "M");
}
