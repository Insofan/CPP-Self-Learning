//
// Created by Insomnia on 2018/6/13.
//
/**
 * leetcode 206 链表逆序
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 * 构造函数 ListNode(int x) : val(x), next(NULL) {}
 */

#include <stdio.h>
#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *newHead = NULL;
        while (head) {
            ListNode *next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }

        return newHead;
    }
};

int main() {
    ListNode listNode1(1);
    ListNode listNode2(2);
    ListNode listNode3(3);
    ListNode listNode4(4);
    ListNode listNode5(5);
    listNode1.next = &listNode2;
    listNode2.next = &listNode3;
    listNode3.next = &listNode4;
    listNode4.next = &listNode5;
    listNode5.next = NULL;

    ListNode *head = &listNode1;
    std::cout << "Before reverse" << std::endl;
    while (head) {
        std::cout << head->val << std::endl;
        head = head->next;
    }

    Solution solution;
    head = solution.reverseList(&listNode1);
    std::cout << "After reverse" << std::endl;
    while (head) {
        std::cout << head->val << std::endl;
        head = head->next;
    }

    return 0;
}
