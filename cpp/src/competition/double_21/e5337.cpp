// https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/

#include "extern.h"

class S5337 {
    /// ��Ԫ����״̬���б���
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
        unordered_map<char, int> aeiou = { {'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4} }; // ��Ҫ��ӷֺ�
        vector<pair<int, int>> stat(32, { INVALID, INVALID });  // �����״̬��Ϣ
        vector<bool> cur_aeiou(5, false);                     // ��ǰ��Ԫ��״̬
        int int_aeiou = 0;                                    // ������Ԫ��״̬
        // ɨ�ַ����Ը���״̬��Ϣ
        for (int idx = 0; idx < s.size(); ++idx) {
            if (stat[int_aeiou].first == INVALID)
                stat[int_aeiou].first = idx;                  // ֻ�е�һ������״̬ʱ������Ҫ��¼*��һ����ĸ����ǰ����*
            if (aeiou.find(s[idx]) != aeiou.end()) {
                cur_aeiou[aeiou[s[idx]]] = !cur_aeiou[aeiou[s[idx]]];
                int_aeiou = aeiou_to_int(cur_aeiou);          // ֻ����ĸ��Ԫ���������£�����Ҫ����Ԫ��״̬�ı���
            }
            stat[int_aeiou].second = idx;                     // ��ĸ���� idx ֻ��Խ��Խ�����ÿ�ζ���¼��ǰ���� idx �µ�*���һ����ĸ���������*
        }
        // ��״̬��Ϣ�У���*���һ����ĸ���������*��*��һ����ĸ����ǰ����*�Ĳ�����õ����
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

/* ��⣺
   https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/solution/bao-cun-32-chong-zhuang-tai-mei-you-shi-yong-yi-we/
*/
