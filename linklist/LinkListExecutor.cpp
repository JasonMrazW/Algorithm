//
// Created by bo on 2022/3/9.
//

#include "LinkListExecutor.h"

ListNode *LinkListExecutor::detectCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)break;
    }

    if (slow != fast) {
        return nullptr;
    }

    ListNode *other = head;
    while (other!=fast) {
        other = other->next;
        fast = fast->next;
    }
    return other;
}

ListNode *LinkListExecutor::getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a_p = headA;
    ListNode *b_p = headA;

    //分别取链表的长度
    int a_length = 1;
    while (a_p->next != nullptr) {
        a_length++;
        a_p = a_p->next;
    }

    int b_length = 1;
    while (b_p->next != nullptr) {
        b_length++;
        b_p = b_p->next;
    }

    if (a_p != b_p) {
        return nullptr;
    }
    //判断二者的差距
    int distance = abs(a_length - b_length);
    a_p = headA;
    b_p = headB;

    if (a_length > b_length) {
        int i = distance;
        while (i-->0) {
            a_p = a_p->next;
        }
    } else {
        int i = distance;
        while (i-->0) {
            b_p = b_p->next;
        }
    }

    //二者到同一个起点了
    while (a_p->val != b_p->val) {
        a_p = a_p->next;
        b_p = b_p->next;
    }

    return a_p;
}

ListNode *LinkListExecutor::removeNthFromEnd(ListNode *head, int n) {
    ListNode *fake_head = new ListNode(0, head);
    ListNode *fast = head;
    ListNode *slow = fake_head;
    int size = 0;

    int i = 0;
    while (i++ < n) {
        fast = fast->next;
    }

    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode *target = slow->next;
    if (target != nullptr) {
        slow->next = target->next;
    } else {
        slow->next = nullptr;
    }

    ListNode *ret = fake_head->next;
    delete fake_head;

    return ret;
}