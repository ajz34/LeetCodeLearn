// https://leetcode-cn.com/problems/restore-ip-addresses/

#include "extern.h"

class S0093 {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        auto valid_num = [](const string& num) {
            if (num.front() == '0') return num.size() == 1;
            return stoi(num) <= 255;
        };
        for (int i = 1; i <= 3; ++i) {
            if (s.size() - i <= 9 && s.size() - i >= 3 && valid_num(s.substr(0, i)))
                for (int j = i + 1; j <= i + 3; ++j) {
                    if (s.size() - j <= 6 && s.size() - j >= 2 && valid_num(s.substr(i, j - i)))
                        for (int k = j + 1; k <= j + 3; ++k) {
                            if (s.size() - k <= 3 && s.size() - k >= 1 && valid_num(s.substr(j, k - j)) && valid_num(s.substr(k)))
                                result.push_back(s.substr(0, i) + "." + s.substr(i, j - i) + "." + s.substr(j, k - j) + "." + s.substr(k));
                        }
                }
        }
        return result;
    }
};

TEST(e0100, e0093) {
    set<string> ans{ "255.255.11.135", "255.255.111.35" };
    vector<string> res_vec = S0093().restoreIpAddresses("25525511135");
    set<string> res(res_vec.begin(), res_vec.end());
    ASSERT_THAT(res, ans);
}
