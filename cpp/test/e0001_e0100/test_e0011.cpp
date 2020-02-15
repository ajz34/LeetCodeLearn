//
// Created by ajz34 on 2020/2/11.
//

#include "pch.h"
#include "../../src/e0001_e0100/e0011.h"

TEST(e0001_e0100, e0011) {
    vector<int> v{ 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    ASSERT_EQ(Solution().maxArea(v), 49);
}