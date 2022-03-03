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

int QueueExecutor::numIslands(vector<vector<int>> &grid) {
    queue<vector<int>> land_queue;
    int m = grid.size(), n = grid[0].size();
    int flag = 10;
    int count = 0;
    for (int row = 0; row < m; ++row) {
        for (int col = 0; col < n; ++col) {
            //陆地
            if (grid[row][col] == 1) {
                land_queue.push({row, col});
                while (!land_queue.empty()) {
                    vector<int> point = land_queue.front();
                    land_queue.pop();
                    int rowIndex = point[0];
                    int colIndex = point[1];
                    for (vector<int> direction: DISTANCE) {
                        int r = rowIndex + direction[0];
                        int c = colIndex + direction[1];
                        if (r < 0 || c < 0 || r >=m || c >= n || grid[r][c] == 0 || grid[r][c] > 1){
                            continue;
                        }
                        grid[r][c] = flag;
                        land_queue.push({r, c});
                    }
                }
                count++;
            }
        }
    }
    return count;
}

//==========================================
//打开转盘锁
int QueueExecutor::openLock(vector<string> &deadends, string target) {
    if (target == "0000") {
        return 0;
    }

    unordered_set<string> dead_sets(deadends.begin(), deadends.end());
    if (dead_sets.count("0000")) {
        return -1;
    }

    //上一个字符
    auto char_pre = [](char x) -> char {
        return (x == '0' ? '9':x-1);
    };

    //下一个字符
    auto char_next = [](char x) -> char {
        return (x == '9' ? '0': x+1);
    };

    auto get_subs = [&](string &x) -> vector<string> {
        vector<string> v;
        for (int i = 0; i < x.length(); ++i) {
            char t = x[i];
            x[i] = char_pre(t);
            v.push_back(x);
            x[i] = char_next(t);
            v.push_back(x);
            //回归原位
            x[i] = t;
        }
        return v;
    };


    string temp = "0000";
    queue<pair<string,int>> queue;
    queue.emplace("0000",0);

    unordered_set<string> seen = {"0000"};
    while (!queue.empty()) {
        auto [front, step] = queue.front();
        queue.pop();
        for (auto &next_str: get_subs(front)) {
            if (!seen.count(next_str) && !dead_sets.count(next_str)) {
                if (next_str == target) {
                    return step + 1;
                }

                queue.emplace(next_str, step+1);
                seen.insert(next_str);
            }
        }
    }

    return -1;
}

void QueueExecutor::execute() {
//    vector<vector<int>> queue =  { {2147483647,-1,0,2147483647 }, {2147483647,2147483647,2147483647,-1 }, {2147483647,-1,2147483647,-1 }, {0,-1,2147483647,2147483647 } };
//    wallsAndGates(queue);
//    vector<vector<int>> queue = {{1,1,1,1,0},{1,1,0,1,0},{1,1,0,0,0},{0,0,0,0,0}};
//    cout << "land count :" << numIslands(queue) << endl;
//    for (int i = 0; i < queue.size(); ++i) {
//        cout << "[";
//        for (int j = 0; j < queue[i].size(); ++j) {
//            cout << queue[i][j] << ",";
//        }
//        cout << "]";
//    }

    cout << numSquares(2) << endl;
}

int QueueExecutor::numSquares(int n) {
    queue<pair<int, int>> q;
    q.emplace(n, 1);

    auto is_complete = [](int n) -> bool {
        float t = sqrt(n);
        return t == (int)t;
    };

    int step = 1;
    while (!q.empty()) {
        auto [num, step] = q.front();
        q.pop();
        for (int i = num; i > 0; --i) {
            if (is_complete(i)) {
                int next = num - i;
                if (is_complete(next)) {
                    if (next != 0) {
                        return step + 1;
                    }
                    return step;
                }
                q.emplace(next, step+1);
            }
        }
        step++;
    }
    return step;
}




