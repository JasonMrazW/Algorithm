//
// Created by bo on 2022/3/7.
//

#ifndef ALGORITHM_MYSTACK_H
#define ALGORITHM_MYSTACK_H
#include "../common.h"
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> input_queue;
    queue<int> data;

    MyStack() {

    }

    void push(int x) {
        input_queue.push(x);
        while (!data.empty()) {
            input_queue.push(data.front());
            data.pop();
        }
        queue<int> temp = input_queue;
        input_queue = data;
        data = temp;
    }

    int pop() {
        int x = data.front();
        data.pop();
        return x;
    }

    int top() {
        if (empty()) return -1;

        return data.front();
    }

    bool empty() {
        return data.empty();
    }
};
#endif //ALGORITHM_MYSTACK_H
