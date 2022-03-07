//
// Created by bo on 2022/3/7.
//

#ifndef ALGORITHM_NODE_H
#define ALGORITHM_NODE_H
#include "../common.h"

using namespace std;
class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
#endif //ALGORITHM_NODE_H
