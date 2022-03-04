//
// Created by bo on 2022/3/3.
//

#ifndef ALGORITHM_STACKEXECUTOR_H
#define ALGORITHM_STACKEXECUTOR_H
#include "../common.h"
#include <stack>
using namespace std;

class StackExecutor: public IExecutor {
private:
    int left = 1;
    int right = 2;
public:
    StackExecutor():IExecutor() {

    }

    void execute() override;

    bool isValid(string s);

    //678：有效字符串
    bool checkValidString(string s);

    //038:温度
    vector<int> dailyTemperatures(vector<int>& temperatures);
};


#endif //ALGORITHM_STACKEXECUTOR_H
