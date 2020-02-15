//
// Created by ajz34 on 2020/2/11.
//

#include "pch.h"
#include "../../src/e0001_e0100/e0007.h"

TEST(e0001_e0100, e0007) {
    ASSERT_EQ(Solution().reverse(123), 321);
    ASSERT_EQ(Solution().reverse(-1020), -201);
    ASSERT_EQ(Solution().reverse(1534236469), 0);
    ASSERT_EQ(Solution().reverse(-2147483648), 0);
}