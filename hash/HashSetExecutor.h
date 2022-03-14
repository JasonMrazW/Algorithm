//
// Created by bo on 2022/3/11.
//

#ifndef ALGORITHM_HASHSETEXECUTOR_H
#define ALGORITHM_HASHSETEXECUTOR_H
#include "../common.h"

using namespace std;
class HashSetExecutor:public IExecutor {
public:
    HashSetExecutor():IExecutor(){}

private:
    void execute() override;

public:

    //217. 存在重复元素
    bool containsDuplicate(vector<int>& nums);

    //136. 只出现一次的数字
    int singleNumber(vector<int>& nums);

    //137. 只出现一次的数字
    int singleNumber2(vector<int>& nums);

    //260. 只出现一次的数字 III
    vector<int> singleNumber3(vector<int>& nums);

    //349. 两数组交集
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2);

    //202. 快乐数
    bool isHappy(int n);

    //205. 同构字符串
    bool isIsomorphic(string s, string t);
};


#endif //ALGORITHM_HASHSETEXECUTOR_H
