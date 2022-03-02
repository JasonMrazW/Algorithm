//
// Created by bo on 2022/3/2.
//

#ifndef ALGORITHM_ARRAYEXECUTOR_H
#define ALGORITHM_ARRAYEXECUTOR_H
#include "../common.h"

class ArrayExecutor: public IExecutor {
public:
    ArrayExecutor(): IExecutor() {}
    ~ArrayExecutor() {}
    int removeElement(std::vector<int> &input, int val);

    //找数组中1的个数最长的长度
    int findMaxConsecutiveOnes(std::vector<int>& nums);

    //找数组中最小长度子数组
    int minSubArrayLen(int target, std::vector<int>& nums);

    //杨辉三角
    std::vector<std::vector<int>> generate(int numRows);

    //获取杨辉三角的第n行
    std::vector<int> getRow(int row);

    //找旋转数组中的最小元素，时间复杂度O(n)
    int findMin(std::vector<int>& nums);

    //找旋转数组中的最小元素，时间复杂度O(logN)
    int findMin2(std::vector<int>& nums);

    //删除数组中重复元素
    int removeDuplicates(std::vector<int>& nums);

    //80. 删除有序数组中的重复项 II
    int removeDuplicates2(std::vector<int>& nums);

    //283. 移动零
    void moveZeroes(std::vector<int>& nums);

    void execute() override;
};


#endif //ALGORITHM_ARRAYEXECUTOR_H
