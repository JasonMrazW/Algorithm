//
// Created by bo on 2022/3/9.
//

#ifndef ALGORITHM_LINKLISTEXECUTOR_H
#define ALGORITHM_LINKLISTEXECUTOR_H
#include "../common.h"
#include "ListNode.h"

using namespace std;

class LinkListExecutor:IExecutor {
public:
    LinkListExecutor(): IExecutor() {}

    //142. 环形链表 II
    ListNode *detectCycle(ListNode *head);

    //160.相交链表
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

    //19. 删除链表的倒数第 N 个结点
    ListNode* removeNthFromEnd(ListNode* head, int n);

    //206. 反转链表
    ListNode* reverseList(ListNode* head);
    ListNode* fake_head;
    ListNode* reverseList2(ListNode* head);
};


#endif //ALGORITHM_LINKLISTEXECUTOR_H
