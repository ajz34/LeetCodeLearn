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
        // 0. �ų��������������Ϊ�գ������ཻ�ڵ����ͷ�ڵ�
        if (!headA || !headB) return nullptr;
        if (headA == headB) return headA;
        // 1. �õ����� A ���� `lA` ������ B ���� `lB`
        // ����������У������������ A �еĽڵ��� B ͷ�ڵ� `headB` ��ͬ���򷵻� B ͷ�ڵ�
        // ���� B �� A ��ͷ�ڵ���Ȼ
        // �������β�ڵ㲻��ͬ���򲻿������ཻ�ڵ�
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
        // 2. ������� A ����С�� B���򽻻����� A �� B �����Ч��
        bool reversed = lA < lB;
        if (reversed) swap(headA, headB);
        // 3. ��ת B �б����ཻ�ڵ�֮�������ȼ�Ϊ `lC`
        reverseList(headB);
        headB->next = headA;
        int lL = 1; ListNode* node = headB;
        while (node->next != headB) {
            node = node->next;
            lL += 1;
        }
        int lC = (lA + lB - lL + 1) / 2;
        // 4. ��ԭ B �б�����ԭ�������� A �� B ����
        reverseList(lastB, headA);
        if (reversed) swap(headA, headB);
        // 5. ͨ�� `lC` �� `lB` �����ཻ�Ľڵ㡣
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

/* ��⣺
   https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/po-pi-lian-biao-cheng-huan-zai-huan-yuan-tu-jie-bu/
*/
