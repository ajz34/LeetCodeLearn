//
// Created by ajz34 on 2020/2/11.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "e0001_e0100/e0009_palindrome_number.h"
using namespace testing;

TEST(TEST_e0001_e0100, TEST_e0009) {
    ASSERT_TRUE(Solution().isPalindrome(121));
    ASSERT_FALSE(Solution().isPalindrome(-121));
    ASSERT_FALSE(Solution().isPalindrome(10));
}