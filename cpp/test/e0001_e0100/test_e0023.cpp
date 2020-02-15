#include "pch.h"
#include "../../src/e0001_e0100/e0023.h"

TEST(e0001_e0100, e0023) {
    vector<ListNode*> lists{ new ListNode({ 1, 4, 5 }), new ListNode({ 1, 3, 4 }), new ListNode({ 2, 6 }) };
    ASSERT_THAT(Solution().mergeKLists(lists)->to_vector(), (vector<int>{ 1, 1, 2, 3, 4, 4, 5, 6 }));
}