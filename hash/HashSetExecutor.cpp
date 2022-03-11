//
// Created by bo on 2022/3/11.
//

#include "HashSetExecutor.h"

bool HashSetExecutor::containsDuplicate(vector<int> &nums) {
    unordered_set<int> set;
    for (int num: nums) {
        if (set.count(num)) {
            return true;
        } else {
            set.emplace(num);
        }
    }
    return false;
}

int HashSetExecutor::singleNumber(vector<int> &nums) {
    int ret = 0;
    for (int num: nums) {
        ret = num^ret;
    }
    return ret;
}
