//
// Created by ajz34 on 2020/2/11.
//

#include "pch.h"
#include "../../src/e0001_e0100/e0008.h"

TEST(e0001_e0100, e0008) {
    auto a = Solution().myAtoi("42");
    ASSERT_EQ(Solution().myAtoi("42"), 42);
    ASSERT_EQ(Solution().myAtoi("   -42"), -42);
    ASSERT_EQ(Solution().myAtoi("4193 with words"), 4193);
    ASSERT_EQ(Solution().myAtoi("words and 987"), 0);
    ASSERT_EQ(Solution().myAtoi("-91283472332"), -2147483648);
    ASSERT_EQ(Solution().myAtoi("  0000000000012345678"), 12345678);
    ASSERT_EQ(Solution().myAtoi("000000000000000000"), 0);
    ASSERT_EQ(Solution().myAtoi("+"), 0);
    ASSERT_EQ(Solution().myAtoi("20000000000000000000"), 2147483647);
}