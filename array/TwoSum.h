//
// Created by bo on 2022/3/2.
//

#ifndef ALGORITHM_TWOSUM_H
#define ALGORITHM_TWOSUM_H
#include "../common.h"

class TwoSum {
public:
    static std::vector<int> twoSum(std::vector<int>& numbers, int target);

    static std::vector<int> twoSum2Pointer(std::vector<int>& numbers, int target);
};


#endif //ALGORITHM_TWOSUM_H
