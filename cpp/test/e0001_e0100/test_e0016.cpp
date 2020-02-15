//
// Created by ajz34 on 2020/2/12.
//

#include "pch.h"
#include "../../src/e0001_e0100/e0016.h"

TEST(e0001_e0100, e0016) {
    vector<int> v{ -1, 2, 1, -4 };
    ASSERT_EQ(Solution().threeSumClosest(v, 1), 2);
}