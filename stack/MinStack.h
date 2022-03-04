//
// Created by bo on 2022/3/3.
//

#ifndef ALGORITHM_MINSTACK_H
#define ALGORITHM_MINSTACK_H
#include "../common.h"

using namespace std;

class MinStack {
private:
    vector<int> data;
    vector<int> min_data;
public:
    MinStack() {
        min_data.push_back(INT32_MAX);
    }

    void push(int val) {
        data.push_back(val);
        min_data.push_back(min(min_data.back(), val));
    }

    void pop() {
        if (data.empty()) {
            return;
        }
        data.pop_back();
        min_data.pop_back();
    }

    int top() {
        if (data.empty()) {
            return -1;
        }
        return data.back();
    }

    int getMin() {
        return min_data.back();
    }
};
#endif //ALGORITHM_MINSTACK_H
