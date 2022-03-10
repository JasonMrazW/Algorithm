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
