//
// Created by ajz34 on 2020/2/12.
//

#include "pch.h"
#include "../../src/e0001_e0100/e0020.h"

TEST(e0001_e0100, e0020) {
    ASSERT_TRUE(Solution().isValid("()"));
    ASSERT_TRUE(Solution().isValid("((([]){}))"));
    ASSERT_FALSE(Solution().isValid("(]"));
    ASSERT_FALSE(Solution().isValid("){"));
}