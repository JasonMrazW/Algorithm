//
// Created by bo on 2022/3/9.
//

#ifndef ALGORITHM_LISTNODE_H
#define ALGORITHM_LISTNODE_H
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif //ALGORITHM_LISTNODE_H
