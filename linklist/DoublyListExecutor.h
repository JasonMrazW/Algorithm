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

    //138. 复制带随机指针的链表
    unordered_map<Node*, Node*> node_map;
    Node* copyRandomList(Node* head);
    Node* getNodeFromSet(Node* node);
};


#endif //ALGORITHM_DOUBLYLISTEXECUTOR_H
