//
// Created by ajz34 on 2020/2/11.
//

#include "pch.h"
#include "../../src/e0001_e0100/e0013.h"

TEST(e0001_e0100, e0013) {
    ASSERT_EQ(Solution().romanToInt("XXVII"), 27);
    ASSERT_EQ(Solution().romanToInt("MCMXCIV"), 1994);
}