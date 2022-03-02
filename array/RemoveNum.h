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

    //杨辉三角
    std::vector<std::vector<int>> generate(int numRows);

    //获取杨辉三角的第n行
    std::vector<int> getRow(int row);
    void execute() override;
};


#endif //ALGORITHM_REMOVENUM_H
