// https://leetcode-cn.com/problems/group-anagrams/

#include "extern.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res_map{};
        string idx(26, 0);
        for (auto& s : strs) {
            fill(idx.begin(), idx.end(), 0);
            for (auto c : s) idx[c - 'a'] += 1;
            auto p = res_map.find(idx);
            if (p != res_map.cend()) p->second.push_back(s);
            else res_map[idx] = { s };
        }
        vector<vector<string>> res;
        for (auto& p : res_map) res.push_back(p.second);
        return res;
    }
};
