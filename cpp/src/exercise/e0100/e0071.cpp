// https://leetcode-cn.com/problems/simplify-path/

#include "extern.h"

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk; string dir;

        auto addPath = [&stk](const string& s) {
            if (s.empty() || s == ".") return;
            if (s == "..") {
                if (stk.empty()) return;
                else stk.pop_back();
            }
            else stk.push_back(s);
        };

        for (auto c : path) {
            if (c != '/') { dir += c; continue; }
            addPath(dir);
            dir = "";
        }
        if (!dir.empty()) addPath(dir);

        if (stk.empty()) return "/";
        string result;
        for (auto& d : stk) result += '/' + d;
        return result;
    }
};

TEST(e0100, e0071) {
    ASSERT_EQ(Solution().simplifyPath("/home/")               , "/home"    );
    ASSERT_EQ(Solution().simplifyPath("/../")                 , "/"        );
    ASSERT_EQ(Solution().simplifyPath("/home//foo/")          , "/home/foo");
    ASSERT_EQ(Solution().simplifyPath("/a/./b/../../c/")      , "/c"       );
    ASSERT_EQ(Solution().simplifyPath("/a/../../b/../c//.//") , "/c"       );
    ASSERT_EQ(Solution().simplifyPath("/a//b////c/d//././/.."), "/a/b/c"   );
}
