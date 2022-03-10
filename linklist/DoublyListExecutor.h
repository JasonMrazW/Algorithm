//
// Created by bo on 2022/3/10.
//

#ifndef ALGORITHM_DOUBLYLISTEXECUTOR_H
#define ALGORITHM_DOUBLYLISTEXECUTOR_H
#include "../common.h"
#include "Node.h"

using namespace std;
class DoublyListExecutor : IExecutor{
public:
    DoublyListExecutor(): IExecutor() {}

    //430. 扁平化多级双向链表
    Node* flatten(Node* head);

    Node* flattenChildren(Node* child);
};


#endif //ALGORITHM_DOUBLYLISTEXECUTOR_H
