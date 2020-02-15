//
// Created by ajz34 on 2020/2/11.
//

#include "pch.h"
#include "../../src/e0001_e0100/e0006.h"

TEST(e0001_e0100, e0006) {
    ASSERT_EQ(Solution().convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
    ASSERT_EQ(Solution().convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
    ASSERT_EQ(Solution().convert("A", 1), "A");
}