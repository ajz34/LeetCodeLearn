#include "pch.h"
#include "../../src/e0001_e0100/e0022.h"

TEST(e0001_e0100, e0022) {
    auto res = Solution().generateParenthesis(3);
    set<string> s(res.cbegin(), res.cend());
    set<string> ans{ "((()))", "(()())", "(())()", "()(())", "()()()" };
    ASSERT_THAT(s, ans);
}