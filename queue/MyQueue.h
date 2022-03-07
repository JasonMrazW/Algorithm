//
// Created by bo on 2022/3/7.
//

#ifndef ALGORITHM_MYQUEUE_H
#define ALGORITHM_MYQUEUE_H
#include "../common.h"
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> data;
    stack<int> inverse;

    MyQueue() {

    }

    void push(int x) {
        inverse.push(x);
    }

    int pop() {
        int ret = peek();
        data.pop();
        return ret;
    }

    int peek() {
        if (empty() == true) return -1;

        if (data.empty()) {
            fill_data();
        }

        return data.top();
    }

    bool empty() {
        return data.empty() && inverse.empty();
    }

    void fill_data() {
        while (!inverse.empty()) {
            data.push(inverse.top());
            inverse.pop();
        }
    }
};
#endif //ALGORITHM_MYQUEUE_H
