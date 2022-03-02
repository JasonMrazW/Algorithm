//
// Created by bo on 2022/3/2.
//

#ifndef ALGORITHM_COMMON_H
#define ALGORITHM_COMMON_H
#include <iostream>
#include <vector>
class IExecutor {
public:
    IExecutor() {}
    ~IExecutor() {}
    virtual void execute() = 0;
};
#endif //ALGORITHM_COMMON_H
