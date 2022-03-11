//
// Created by bo on 2022/3/11.
//

#ifndef ALGORITHM_MYHASHMAP_H
#define ALGORITHM_MYHASHMAP_H
#include "../common.h"

using namespace std;

class MyHashMap {
private:
    static const int num = 769;


    static int hashCode(int key) {
        return key % num;
    }
    struct Node {
        int key;
        int value;
        Node(int k, int v):key(k),value(v){};
    };
    vector<list<Node*>> data;
public:
    MyHashMap(): data(num) {

    }

    void put(int key, int value) {
        int code = hashCode(key);
        for (auto it = data[code].begin();it != data[code].end();it++) {
            Node *node = *it;
            if (node->key == key) {
                node->value = value;
                return;
            }
        }

        data[code].push_back(new Node(key,value));
    }

    int get(int key) {
        int code = hashCode(key);
        for (auto it = data[code].begin();it != data[code].end();it++) {
            Node *node = *it;
            if (node->key == key) {
                return node->value;
            }
        }

        return -1;
    }

    void remove(int key) {
        int code = hashCode(key);
        for (auto it = data[code].begin();it != data[code].end();it++) {
            Node *node = *it;
            if (node->key == key) {
                data[code].erase(it);
                return;
            }
        }

        return -1;
    }
};
#endif //ALGORITHM_MYHASHMAP_H
