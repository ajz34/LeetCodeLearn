#include "pch.h"
#include "../../src/e0001_e0100/e0024.h"

TEST(e0001_e0100, e0024) {
    auto l = new ListNode({ 1, 2, 3, 4 });
    ASSERT_THAT(Solution().swapPairs(l)->to_vector(), (vector<int>{ 2, 1, 4, 3 }));
}