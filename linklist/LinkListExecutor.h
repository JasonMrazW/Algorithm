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
};


#endif //ALGORITHM_LINKLISTEXECUTOR_H
