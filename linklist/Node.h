//
// Created by bo on 2022/3/10.
//

#ifndef ALGORITHM_NODE_H
#define ALGORITHM_NODE_H
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node* random;

    Node(int v): val(v){};
};
#endif //ALGORITHM_NODE_H
