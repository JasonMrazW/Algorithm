//
// Created by bo on 2022/3/10.
//

#ifndef ALGORITHM_DOUBLYLISTNODE_H
#define ALGORITHM_DOUBLYLISTNODE_H
struct DoublyListNode {
    int val;
    DoublyListNode *next, *prev;
    DoublyListNode(int x) : val(x), next(NULL), prev(NULL) {}
};
#endif //ALGORITHM_DOUBLYLISTNODE_H
