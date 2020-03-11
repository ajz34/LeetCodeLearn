// https://leetcode-cn.com/problems/reverse-words-in-a-string/

#include "extern.h"

class S0151 {
public:
    string reverseWords(string s) {
        stack<string> stk;
        string t;
        for (char& c : s) {
            switch (c)
            {
            case ' ':
                if (!t.empty()) {
                    stk.push(t);
                    t.clear();
                }
                break;
            default:
                t.push_back(c);
                break;
            }
        }
        if (!t.empty()) stk.push(t);

        string result;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
            if (!stk.empty()) result.push_back(' ');
        }
        return result;
    }
};

TEST(e0200, e0151) {
    ASSERT_EQ(S0151().reverseWords("the sky is blue"), "blue is sky the");
    ASSERT_EQ(S0151().reverseWords("  hello world!"), "world! hello");
    ASSERT_EQ(S0151().reverseWords("a good   example"), "example good a");
}
