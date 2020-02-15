#include "pch.h"
#include "../../src/e0001_e0100/e0025.h"

TEST(e0001_e0100, e0025) {
    auto l = new ListNode({ 1, 2, 3, 4, 5 });
    ASSERT_THAT(Solution().reverseKGroup(l, 2)->to_vector(), (vector<int>{ 2, 1, 4, 3, 5 }));
    l = new ListNode({ 1, 2, 3, 4, 5 });
    ASSERT_THAT(Solution().reverseKGroup(l, 3)->to_vector(), (vector<int>{ 3, 2, 1, 4, 5 }));
    l = new ListNode({ 1, 2, 3, 4, 5 });
    ASSERT_THAT(Solution().reverseKGroup(l, 1)->to_vector(), (vector<int>{ 1, 2, 3, 4, 5 }));
    l = new ListNode({ 1, 2, 3, 4, 5 });
    ASSERT_THAT(Solution().reverseKGroup(l, 5)->to_vector(), (vector<int>{ 5, 4, 3, 2, 1 }));
}