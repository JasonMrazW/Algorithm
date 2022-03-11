//
// Created by bo on 2022/3/11.
//

#ifndef ALGORITHM_HASHSETEXECUTOR_H
#define ALGORITHM_HASHSETEXECUTOR_H
#include "../common.h"

using namespace std;
class HashSetExecutor: IExecutor {
public:
    HashSetExecutor():IExecutor(){}

    //217. 存在重复元素
    bool containsDuplicate(vector<int>& nums);

    //136. 只出现一次的数字
    int singleNumber(vector<int>& nums);
};


#endif //ALGORITHM_HASHSETEXECUTOR_H
