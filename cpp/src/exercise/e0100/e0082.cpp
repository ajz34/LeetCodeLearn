// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/

#include "extern.h"

class S0082{
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* post = new ListNode((head->val == 0) ? 1 : 0);
        post->next = head;
        ListNode* pl = post; ListNode* pr = post->next;
        while (pl->next != nullptr) {
            while (pr->next != nullptr && pl->next->val == pr->next->val) pr = pr->next;
            if (pl->next != pr) {
                pl->next = pr->next;
                if (pr->next) pr = pr->next;
            }
            else {
                pl = pr;
                if (pr->next) pr = pl->next;
            }
        }
        return post->next;
    }
};

TEST(e0100, e0082) {
    ListNode* head; vector<int> ans;
    head = new ListNode(str_to_vec<int>("[1,2,3,3,4,4,5]"));
    ans = str_to_vec<int>("[1,2,5]");
    ASSERT_THAT(S0082().deleteDuplicates(head)->to_vector(), ans);
    head = new ListNode(str_to_vec<int>("[1,1,1,2,3]"));
    ans = str_to_vec<int>("[2,3]");
    ASSERT_THAT(S0082().deleteDuplicates(head)->to_vector(), ans);
}
