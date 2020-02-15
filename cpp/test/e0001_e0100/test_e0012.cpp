//
// Created by ajz34 on 2020/2/11.
//

#include "pch.h"
#include "../../src/e0001_e0100/e0012.h"

TEST(e0001_e0100, e0012) {
    ASSERT_EQ(Solution().intToRoman(27), "XXVII");
    ASSERT_EQ(Solution().intToRoman(1994), "MCMXCIV");
}