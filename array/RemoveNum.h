//
// Created by bo on 2022/3/2.
//

#ifndef ALGORITHM_REMOVENUM_H
#define ALGORITHM_REMOVENUM_H
#include "../common.h"

class RemoveNum: public IExecutor {
public:
    RemoveNum(): IExecutor() {}
    ~RemoveNum() {}
    int removeElement(std::vector<int> &input, int val);

    //找数组中1的个数最长的长度
    int findMaxConsecutiveOnes(std::vector<int>& nums);

    //找数组中最小长度子数组
    int minSubArrayLen(int target, std::vector<int>& nums);
    void execute() override;
};


#endif //ALGORITHM_REMOVENUM_H
