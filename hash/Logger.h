//
// Created by bo on 2022/3/14.
//

#ifndef ALGORITHM_LOGGER_H
#define ALGORITHM_LOGGER_H
#include "../common.h"

using namespace std;

class Logger {
public:
    unordered_map<string, int> kv;
    unordered_set<string> data_set;
    queue<pair<string,int>> data_queue;

    Logger() {

    }

    bool shouldPrintMessage(int timestamp, string message) {
        while (data_queue.size() > 0) {
            auto [mk, k] = data_queue.front();
            if ((timestamp - k) >= 10) {
                data_queue.pop();
                data_set.erase(mk);
            } else {
                break;
            }
        }

        if (data_set.count(message)) {
            return false;
        }
        data_set.emplace(message);
        data_queue.emplace(message, timestamp);
        return true;
    }
};
#endif //ALGORITHM_LOGGER_H
