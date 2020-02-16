#include "extern.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk{};
        for (char& c : s) {
            switch (c) {
                case '(': stk.push('('); break;
                case ')': if (stk.empty() || stk.top() != '(') return false; else stk.pop(); break;
                case '[': stk.push('['); break;
                case ']': if (stk.empty() || stk.top() != '[') return false; else stk.pop(); break;
                case '{': stk.push('{'); break;
                case '}': if (stk.empty() || stk.top() != '{') return false; else stk.pop(); break;
                default: assert(false);
            }
        }
        return stk.empty();
    }
};

TEST(e0100, e0020) {
    ASSERT_TRUE(Solution().isValid("()"));
    ASSERT_TRUE(Solution().isValid("((([]){}))"));
    ASSERT_FALSE(Solution().isValid("(]"));
    ASSERT_FALSE(Solution().isValid("){"));
}
