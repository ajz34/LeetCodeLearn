// https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/

#include "extern.h"

class S0150 {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string& s : tokens) {
            if (s.size() == 1 && (s[0] > '9' || s[0] < '0')) {
                int v1 = stk.top(); stk.pop();
                int v2 = stk.top(); stk.pop();
                switch (s[0])
                {
                case '+': stk.push(v2 + v1); break;
                case '-': stk.push(v2 - v1); break;
                case '*': stk.push(v2 * v1); break;
                case '/': stk.push(v2 / v1); break;
                default: assert(false); break;
                }
            }
            else stk.push(stoi(s));
        }
        assert(stk.size() == 1);
        return stk.top();
    }
};

TEST(e0200, e0150) {
    vector<string> tokens;
    tokens = { "2", "1", "+", "3", "*" };
    ASSERT_EQ(S0150().evalRPN(tokens), 9);
    tokens = { "4", "13", "5", "/", "+" };
    ASSERT_EQ(S0150().evalRPN(tokens), 6);
    tokens = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
    ASSERT_EQ(S0150().evalRPN(tokens), 22);
}
