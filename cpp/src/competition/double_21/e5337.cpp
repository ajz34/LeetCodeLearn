// https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/

#include "extern.h"

class S5337 {
    /// 将元音的状态进行编码
    int aeiou_to_int(const vector<bool>& b) {
        int r = 0, m = 1;
        for (auto v : b) {
            if (v) r += m;
            m *= 2;
        }
        return r;
    }
public:
    int findTheLongestSubstring(string s) {
        int INVALID = -1;
        unordered_map<char, int> aeiou = { {'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4} }; // 需要后接分号
        vector<pair<int, int>> stat(32, { INVALID, INVALID });  // 保存的状态信息
        vector<bool> cur_aeiou(5, false);                     // 当前的元音状态
        int int_aeiou = 0;                                    // 编码后的元音状态
        // 扫字符串以更新状态信息
        for (int idx = 0; idx < s.size(); ++idx) {
            if (stat[int_aeiou].first == INVALID)
                stat[int_aeiou].first = idx;                  // 只有第一次遇到状态时，才需要记录*第一次字母填入前索引*
            if (aeiou.find(s[idx]) != aeiou.end()) {
                cur_aeiou[aeiou[s[idx]]] = !cur_aeiou[aeiou[s[idx]]];
                int_aeiou = aeiou_to_int(cur_aeiou);          // 只有字母是元音的情形下，才需要更新元音状态的编码
            }
            stat[int_aeiou].second = idx;                     // 字母索引 idx 只会越来越大，因此每次都记录当前索引 idx 下的*最后一次字母填入后索引*
        }
        // 从状态信息中，作*最后一次字母填入后索引*与*第一次字母填入前索引*的差减，得到结果
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            if (stat[i].first == INVALID || stat[i].second == INVALID)
                continue;
            int r = stat[i].second - stat[i].first + 1;
            result = max(result, r);
        }
        return result;
    }
};

TEST(double21, e5337) {
    ASSERT_EQ(S5337().findTheLongestSubstring("eleetminicoworoep"), 13);
    ASSERT_EQ(S5337().findTheLongestSubstring("leetcodeisgreat"), 5);
    ASSERT_EQ(S5337().findTheLongestSubstring("bcbcbc"), 6);
}

/* 题解：
   https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/solution/bao-cun-32-chong-zhuang-tai-mei-you-shi-yong-yi-we/
*/
