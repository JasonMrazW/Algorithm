//
// Created by bo on 2022/3/2.
//

#ifndef ALGORITHM_STRINGEXECUTOR_H
#define ALGORITHM_STRINGEXECUTOR_H
#include "../common.h"
using namespace std;

class StringExecutor : public IExecutor{
public:
    StringExecutor(): IExecutor() {

    }
    ~StringExecutor() {}

    string reverseWords(string s);

    void execute() override;
};


#endif //ALGORITHM_STRINGEXECUTOR_H
