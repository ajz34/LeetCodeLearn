//
// Created by ajz34 on 2020/2/11.
//

#include "pch.h"
#include "../../src/e0001_e0100/e0009.h"

TEST(e0001_e0100, e0009) {
    ASSERT_TRUE(Solution().isPalindrome(121));
    ASSERT_FALSE(Solution().isPalindrome(-121));
    ASSERT_FALSE(Solution().isPalindrome(10));
}