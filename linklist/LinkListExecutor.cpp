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

ListNode *LinkListExecutor::reverseList(ListNode *head) {
//    if (head == nullptr) return nullptr;
//    ListNode *fake_head = new ListNode(0, head);
//    ListNode *p = head;
//    ListNode *target = p->next;
//    if (target == nullptr) return head;
//    while (target) {
//        ListNode *temp = fake_head->next;
//        fake_head->next = target;
//        p->next = target->next;
//        target->next = temp;
//
//        target = p->next;
//    }
//    return fake_head->next;
    fake_head = new ListNode(0, head);
    return reverseList2(fake_head->next);
}

ListNode *LinkListExecutor::reverseList2(ListNode *head) {
    if (head->next == nullptr) {
        return head;
    }
    ListNode *new_head = reverseList2(head->next);
    head->next->next = head;
    head->next = nullptr;

    return new_head;
}

ListNode *LinkListExecutor::removeElements(ListNode *head, int val) {
    if (head == nullptr) {
        return nullptr;
    }
    ListNode* fakeHead = new ListNode(0, head);
    ListNode* node = fakeHead;
    while (node&&node->next) {
        if (node->next->val == val) {
            node->next = node->next->next;
        } else {
            node = node->next;
        }
    }
    return fakeHead->next;
}

ListNode *LinkListExecutor::oddEvenList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode *old = head;
    ListNode *event = old->next;
    ListNode *event_head = event;
    while (old && event) {
        old->next = event->next;
        if (old->next != nullptr) {
            old = old->next;
        } else {
            break;
        }
        event->next = old->next;
        event = event->next;
    }

    old->next = event_head;

    return head;
}

bool LinkListExecutor::isPalindrome(ListNode *head) {
    start_node = head;
    return checkPalindrome(head);
}

bool LinkListExecutor::checkPalindrome(ListNode *node) {
    if (node != nullptr) {
        if (!checkPalindrome(node->next)) {
            return false;
        }
        if (node->val != start_node->val) {
            return false;
        }
        start_node = start_node->next;
    }

    return true;
}

ListNode *LinkListExecutor::addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *ret_fake_header = new ListNode(0);
    ListNode *first = l1;
    ListNode *second = l2;
    ListNode *ret_p = ret_fake_header;
    int val = 0;
    int ten = 0;
    while (first && second) {
        val = first->val + second->val + ten;
        ListNode *node = new ListNode(val%10);
        ret_p->next = node;
        ret_p = ret_p->next;
        ten = val/10;

        first = first->next;
        second = second->next;
    }

    ListNode *temp = first == nullptr? second:first;

    while (temp) {
        val = temp->val + ten;
        ListNode *node = new ListNode(val%10);
        ret_p->next = node;
        ret_p = ret_p->next;
        ten = val/10;

        temp = temp->next;
    }
    if (ten == 1) {
        ListNode *node = new ListNode(1);
        ret_p->next = node;
    }

    return ret_fake_header->next;
}

ListNode *LinkListExecutor::rotateRight(ListNode *head, int k) {
    //1. 获取链表长度，且找到最后一个节点的指针
    ListNode *fake_head = new ListNode(0, head);
    ListNode *p = fake_head->next;
    int length = 0;
    while (p) {
        length++;
        if (p->next == nullptr) {
            break;
        }
        p = p->next;
    }

    //2. 求一轮要挪多少步
    int n = k%length;
    if (n == 0) return head;

    //3. 找到第n-1节点
    ListNode *q = fake_head;
    int step = length - n;
    while (step > 0) {
        q = q->next;
        step--;
    }

    //4. 换节点
    ListNode *temp = fake_head->next;
    fake_head->next = q->next;
    cout << temp->val << endl;
    p->next = temp;
    q->next = nullptr;

    return fake_head->next;
}
