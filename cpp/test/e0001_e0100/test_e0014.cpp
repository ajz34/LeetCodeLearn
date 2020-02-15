//
// Created by ajz34 on 2020/2/11.
//

#include "pch.h"
#include "../../src/e0001_e0100/e0014.h"

TEST(e0001_e0100, e0014) {
    vector<string> v { "flower", "flow", "flight" };
    ASSERT_EQ(Solution().longestCommonPrefix(v), "fl");
    vector<string> l { "dog", "racecar", "car" };
    ASSERT_EQ(Solution().longestCommonPrefix(l), "");
}