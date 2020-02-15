//
// Created by ajz34 on 2020/2/12.
//

#include "pch.h"
#include "../../src/e0001_e0100/e0018.h"

TEST(e0001_e0100, e0018) {
    vector<int> v { 1, 0, -1, 0, -2, 2 };
    vector<vector<int>> r {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
    ASSERT_THAT(Solution().fourSum(v, 0), r);
}