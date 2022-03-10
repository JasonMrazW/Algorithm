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

Node *DoublyListExecutor::copyRandomList(Node *head) {
    if (head == nullptr) return nullptr;
    Node *ret_head = getNodeFromSet(head);
    Node *old_cur = head;
    Node *new_cur = ret_head;


    int index = 0;
    while (old_cur) {
        new_cur->val = old_cur->val;
        if (old_cur->random != nullptr) {
            new_cur->random = getNodeFromSet(old_cur->random);
        }
        if (old_cur->next != nullptr) {
            new_cur->next = getNodeFromSet(old_cur->next);
            old_cur = old_cur->next;
            new_cur = new_cur->next;
        } else {
            break;
        }
    }

    return ret_head;
}

Node *DoublyListExecutor::getNodeFromSet(Node* node) {
    if (node == nullptr)return nullptr;
    Node *next;
    if (node_map.count(node)) {
        next = node_map[node];
    } else {
        next = new Node(node->val);
        node_map.emplace(node, next);
    }
    return next;
}
