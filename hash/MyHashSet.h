//
// Created by bo on 2022/3/10.
//

#ifndef ALGORITHM_MYHASHSET_H
#define ALGORITHM_MYHASHSET_H
#include "../common.h"
using namespace std;

class MyHashSet {
private:
    static const int num = 10;
    vector<list<int>> data;
    static int hashCode(int key) {
        return key % num;
    }

public:
    MyHashSet():data(num) {

    }

    void add(int key) {
        int code = hashCode(key);
        for (auto it = data[code].begin(); it != data[code].end() ; ++i) {
            //already exist
            if(*it == key) {
                return;
            }
        }
        data[code].push_back(key);
    }

    void remove(int key) {
        int code = hashCode(key);
        for (auto it = data[code].begin(); it != data[code].end() ; ++i) {
            //already exist
            if(*it == key) {
                data[code].erase(it);
                return;
            }
        }
    }

    bool contains(int key) {
        int code = hashCode(key);
        for (auto it = data[code].begin(); it != data[code].end() ; ++i) {
            //already exist
            if(*it == key) {
                return true;
            }
        }
        return false;
    }
};
#endif //ALGORITHM_MYHASHSET_H
