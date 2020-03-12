// https://leetcode-cn.com/problems/intersection-of-two-linked-lists/

#include "extern.h"

class S0160 {
    void reverseList(ListNode* head, ListNode* last = nullptr) {
        if (head->next == last) return;
        ListNode* pp = head, * p = head->next, * pn;
        while (p != last) {
            pn = p->next;
            p->next = pp;
            pp = p;
            p = pn;
        }
        head->next = nullptr;
    }

public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // 0. 排除极端情况：链表为空，或者相交节点就是头节点
        if (!headA || !headB) return nullptr;
        if (headA == headB) return headA;
        // 1. 得到链表 A 长度 `lA` 与链表 B 长度 `lB`
        // 在这个过程中，如果发现链表 A 中的节点与 B 头节点 `headB` 相同，则返回 B 头节点
        // 链表 B 与 A 的头节点亦然
        // 如果链表尾节点不相同，则不可能有相交节点
        ListNode* lastA = headA, * lastB = headB;
        int lA = 1, lB = 1;
        while (lastA->next) {
            lastA = lastA->next; ++lA;
            if (lastA == headB) return headB;
        }
        while (lastB->next) {
            lastB = lastB->next; ++lB;
            if (lastB == headA) return headA;
        }
        if (lastA != lastB) return nullptr;
        // 2. 如果链表 A 长度小于 B，则交换链表 A 与 B 以提高效率
        bool reversed = lA < lB;
        if (reversed) swap(headA, headB);
        // 3. 反转 B 列表，将相交节点之后链表长度记为 `lC`
        reverseList(headB);
        headB->next = headA;
        int lL = 1; ListNode* node = headB;
        while (node->next != headB) {
            node = node->next;
            lL += 1;
        }
        int lC = (lA + lB - lL + 1) / 2;
        // 4. 还原 B 列表，并还原被交换的 A 与 B 链表
        reverseList(lastB, headA);
        if (reversed) swap(headA, headB);
        // 5. 通过 `lC` 与 `lB` 返回相交的节点。
        ListNode* result = headB;
        for (int i = 0; i < lB - lC; ++i)
            result = result->next;
        return result;
    }
};

// Testing is incomplete since address of nodes are not counted.

TEST(e0200, e0160) {
    auto listTail = [](ListNode* head) {
        ListNode* result = nullptr;
        if (!head) return result;
        while (head->next) head = head->next;
        return head;
    };
    ListNode* listA, * listB, * listC;

    listA = new ListNode("[4,1]");
    listB = new ListNode("[5,0,1]");
    listC = new ListNode("[8,4,5]");
    listTail(listA)->next = listC;
    listTail(listB)->next = listC;
    ASSERT_EQ(S0160().getIntersectionNode(listA, listB), listC);

    listA = new ListNode("[0,9,1]");
    listB = new ListNode("[3]");
    listC = new ListNode("[2,4]");
    listTail(listA)->next = listC;
    listTail(listB)->next = listC;
    ASSERT_EQ(S0160().getIntersectionNode(listA, listB), listC);

    listA = new ListNode("[2,6,4]");
    listB = new ListNode("[1,5]");
    listC = nullptr;
    listTail(listA)->next = listC;
    listTail(listB)->next = listC;
    ASSERT_EQ(S0160().getIntersectionNode(listA, listB), listC);
}

/* 题解：
   https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/po-pi-lian-biao-cheng-huan-zai-huan-yuan-tu-jie-bu/
*/
