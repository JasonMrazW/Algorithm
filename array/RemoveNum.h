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
    int findMaxConsecutiveOnes(std::vector<int>& nums);
    void execute() override;
};


#endif //ALGORITHM_REMOVENUM_H
