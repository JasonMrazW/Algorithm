//
// Created by bo on 2022/3/2.
//

#ifndef ALGORITHM_MYCIRCULARQUEUE_H
#define ALGORITHM_MYCIRCULARQUEUE_H
#include "../common.h"
using namespace std;

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        array = vector<int>(k);
        head = -1;
        tail = -1;
        size = k;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        tail = (tail + 1) % size;
        if (head < 0) {
            head = 0;
        }
        array[tail] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        if (head == tail) {
            head = -1;
            tail = -1;
        } else {
            head = (head+1) % size;
        }
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return array[head];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }

        return array[tail];
    }

    bool isEmpty() {
        return head < 0 && tail < 0;
    }

    bool isFull() {
        bool  ret = (tail + 1) % size == head;
        return ret;
    }

private:
    int head = -1, tail = -1;
    int size = 0;
    std::vector<int> array;
};


#endif //ALGORITHM_MYCIRCULARQUEUE_H
