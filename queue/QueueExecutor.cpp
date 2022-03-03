//
// Created by bo on 2022/3/3.
//

#include "QueueExecutor.h"

static const int WALL = -1;
static const int GATE = 0;
static const int EMPTY = INT32_MAX;
static const vector<vector<int>> DISTANCE = {
        {1, 0},
        {-1,0},
        {0, 1},
        {0,-1}
};

void QueueExecutor::wallsAndGates(vector<vector<int>> &rooms) {
    queue<vector<int>> gate_queue;
    for (int rowIndex = 0; rowIndex < rooms.size(); rowIndex++) {
        for (int col = 0; col < rooms[rowIndex].size(); ++col) {
            if (rooms[rowIndex][col] == GATE) {
                gate_queue.push({rowIndex, col});
            }
        }
    }

    int m = rooms.size();
    int n = rooms[0].size();
    while (!gate_queue.empty()) {
        vector<int> point = gate_queue.front();
        gate_queue.pop();
        int row = point[0], col = point[1];
        for (vector<int> direction: DISTANCE) {
            int r = row + direction[0];
            int c = col + direction[1];
            if (r < 0 || c < 0 || r >= m || c >= n || rooms[r][c] != EMPTY) {
                continue;
            }
            rooms[r][c] = rooms[row][col] + 1;
            gate_queue.push({r, c});
        }
    }
}

int QueueExecutor::getDistance(vector<vector<int>> &rooms, int rowIndex, int colIndex) {
    queue<vector<int>> queue;
    queue.push({rowIndex, colIndex});

    int m = rooms.size();
    int n = rooms[0].size();
    vector<vector<int>> d(m, vector<int>(n, 0));
    while (!queue.empty()) {
        vector<int> point = queue.front();
        queue.pop();
        int row = point[0], col = point[1];
        for (vector<int> direction: DISTANCE) {
            int r = row + direction[0];
            int c = col + direction[1];
            if (r < 0 || c < 0 || r >= m || c >= n || rooms[r][c] == WALL || d[r][c] != 0) {
                continue;
            }
            d[r][c] = d[row][col] + 1;
            if (rooms[r][c] == GATE) {
                return d[r][c];
            }
            queue.push({r,c});
        }
    }

    return INT32_MAX;
}

int QueueExecutor::numIslands(vector<vector<char>> &grid) {
    
    return 0;
}

void QueueExecutor::execute() {
    vector<vector<int>> queue =  { {2147483647,-1,0,2147483647 }, {2147483647,2147483647,2147483647,-1 }, {2147483647,-1,2147483647,-1 }, {0,-1,2147483647,2147483647 } };
    wallsAndGates(queue);

    for (int i = 0; i < queue.size(); ++i) {
        cout << "[";
        for (int j = 0; j < queue[i].size(); ++j) {
            cout << queue[i][j] << ",";
        }
        cout << "]";
    }
}



