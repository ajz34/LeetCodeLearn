// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/

#include "extern.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* post = new ListNode(head->val == 0 ? 1 : 0);
        post->next = head;
        ListNode* pl = post; ListNode* pr = post->next;
        while (pl->next) {
            while (pr->next && pl->next->val == pr->next->val) pr = pr->next;
            pl->next = pr; pl = pr;
            if (pr->next) pr = pr->next;
        }
        return post->next;
    }
};

TEST(e0100, e0083) {
    ListNode* head; vector<int> ans;
    head = new ListNode(str_to_vec<int>("[1,1,2]"));
    ans = str_to_vec<int>("[1,2]");
    ASSERT_THAT(Solution().deleteDuplicates(head)->to_vector(), ans);
    head = new ListNode(str_to_vec<int>("[1,1,2,3,3]"));
    ans = str_to_vec<int>("[1,2,3]");
    ASSERT_THAT(Solution().deleteDuplicates(head)->to_vector(), ans);
}
