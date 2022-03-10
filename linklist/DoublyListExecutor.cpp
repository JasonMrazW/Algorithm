//
// Created by bo on 2022/3/10.
//

#include "DoublyListExecutor.h"

Node *DoublyListExecutor::flattenChildren(Node *node) {
    Node *head = node;
    Node *next = nullptr;
    Node *end = node;

    while (head) {
        if (head->child) {
            end = flattenChildren(head->child);
            //
            next = head->next;
            if (next != nullptr) {
                next->prev = end;
                end->next = next;
            }

            head->next = head->child;
            head->child->prev = head;
            head->child = nullptr;
            head = end->next;
        } else {
            end = head;
            head = head->next;
        }
    }
    return end;
}

Node *DoublyListExecutor::flatten(Node *head) {
    flattenChildren(head);
    return head;
}
