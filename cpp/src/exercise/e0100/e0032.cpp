// https://leetcode-cn.com/problems/longest-valid-parentheses/

#include "extern.h"

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() <= 1) return 0;
        // 0. Make a numeric representation of s
        vector<int> rep; rep.reserve(s.size());
        rep.push_back(0);
        for (size_t i = 1; i < s.size(); ++i)
            rep.push_back(rep[i - 1] + (s[i] == '(' ? 1 : -1));
        //
        int result = 0; stack<pair<size_t, int>> stk;
        for (size_t i = 0; i < rep.size(); ++i) {
            if (s[i] == '(' && (stk.empty() || rep[i] > stk.top().second))
                stk.push(make_pair(i, rep[i]));
            else if (s[i] == ')') {
                if (stk.empty()) continue;
                if (rep[i] == stk.top().second - 2)
                    stk.pop();
                if (stk.empty()) continue;
                if (rep[i] == stk.top().second - 1)
                    result = max(result, int(i - stk.top().first + 1));
            }
        }
        return result;
    }
};

TEST(e0100, e0032) {
    ASSERT_EQ(Solution().longestValidParentheses("(()"), 2);
    ASSERT_EQ(Solution().longestValidParentheses(")()())"), 4);
}

/*  注释：对于更为简洁的做法，参考官方题解
    https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode/
    上述的代码比较接近于官方题解的方法 3。
*/
