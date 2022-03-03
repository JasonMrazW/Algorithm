//
// Created by bo on 2022/3/3.
//

#ifndef ALGORITHM_QUEUEEXECUTOR_H
#define ALGORITHM_QUEUEEXECUTOR_H
#include "../common.h"
#include <queue>
using namespace std;

class QueueExecutor: public IExecutor{
public:
    QueueExecutor():IExecutor() {}

    void execute() override;

    //墙与门
    void wallsAndGates(vector<vector<int>>& rooms);

    int getDistance(vector<vector<int>>& rooms, int rowIndex, int colIndex);

    //200：岛屿数量
    int numIslands(vector<vector<char>>& grid)
};


#endif //ALGORITHM_QUEUEEXECUTOR_H
