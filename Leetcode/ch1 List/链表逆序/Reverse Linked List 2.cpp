//
// Created by Insomnia on 2018/6/13.
//

/**
 * 逆序链表m到n位置
 * 092
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 */
#include <stdio.h>


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *newHead;
        return newHead;
    }
};

int main() {
    ListNode a(10);
    ListNode b(20);
    ListNode c(30);
    ListNode d(40);
    ListNode e(50);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;

    return 0;
}
