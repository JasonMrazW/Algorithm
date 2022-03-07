//
// Created by bo on 2022/3/3.
//

#include "StackExecutor.h"
static const vector<vector<int>> directions = {
        {1, 0},
        {-1,0},
        {0, 1},
        {0,-1}
};

bool StackExecutor::isValid(string s) {
    int length = s.length();

    if (length % 2 != 0) return false;

    auto isLeft = [](char x) -> bool {
        if (x == '(' || x == '{' || x == '[') {
            return true;
        }
        return false;
    };

    auto is_complte = [](char a, char b) -> bool {
        if( (a == '(' && b == ')') ||
        (a == '[' && b == ']') ||
        (a == '{' && b == '}')) {
            return true;
        }
        return false;
    };

    stack<char> left_stack;
    for (int i = 0; i < length; ++i) {
        if (isLeft(s[i])) {
            left_stack.push(s[i]);
        } else {
            if (left_stack.empty()) {
                return false;
            }
            char t = left_stack.top();
            left_stack.pop();
            if (!is_complte(t, s[i])) {
                return false;
            }
        }
    }
    return left_stack.empty();
}

bool StackExecutor::checkValidString(string s) {
    auto is_left = [](char x)->bool {
        return x == '(';
    };

    stack<int> left_stack;
    stack<int> common_stack;
    for (int i = 0; i < s.length(); ++i) {
        if (is_left(s[i])) {
            left_stack.push(i);
        } else if (s[i] == '*') {
            common_stack.push(i);
        } else {
            if (!left_stack.empty()) {
                left_stack.pop();
            } else if (!common_stack.empty()) {
                common_stack.pop();
            } else {
                return false;
            }
        }
    }

    while (!left_stack.empty()) {
        int top = left_stack.top();
        left_stack.pop();
        if (common_stack.empty()) {
            return false;
        }
        if (top > common_stack.top()) {
            return false;
        }
        common_stack.pop();
    }

    return true;
}

vector<int> StackExecutor::dailyTemperatures(vector<int> &temperatures) {
    stack<int> min_stack;
    vector<int> ret(temperatures.size(), 0);
    for (int i = 0; i < temperatures.size(); ++i) {
        while (!min_stack.empty()) {
            int index = min_stack.top();
            if (temperatures[i] > temperatures[index]) {
                ret[index] = i - index;
            } else {
                break;
            }
            min_stack.pop();
        }
        min_stack.push(i);
    }
    return ret;
}


void StackExecutor::execute() {
//    cout << isValid("){") << endl;
//    cout << checkValidString("((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()") << endl;
//    vector<int> temperatures = {73,74,75,71,69,72,76,73};
//    vector<int> ret = dailyTemperatures(temperatures);
//
//    for (int i = 0; i < ret.size(); ++i) {
//        cout << ret[i] << ",";
//    }
//    cout << endl;
//    vector<string> input = {"2","1","+","3","*"};
//    cout << evalRPN(input) << endl;

vector<vector<char>> queue = {{'1','1','0','0','0'}, {'1','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','1'}};
        cout << "land count :" << numIslands(queue) << endl;
}

int StackExecutor::evalRPN(vector<string> &tokens) {
    stack<int> value;
    auto isNumber =  [](string v) -> bool  {
        if (v == "+" || v == "-" || v == "*" || v == "/") {
            return false;
        } else {
            return true;
        }
    };

    auto getResult = [](int a, int b, string c) -> int {
        if (c == "+") return a + b;
        if (c == "-") return a - b;
        if (c == "*") return a * b;
        if (c == "/") return a / b;
        return 0;
    };
    for (int i = 0; i < tokens.size(); ++i) {
        if (isNumber(tokens[i])) {
            value.push(atoi(tokens[i].c_str()));
        } else {
            int b = value.top();
            value.pop();
            int a = value.top();
            value.pop();
            value.push(getResult(a, b, tokens[i]));
        }
    }
    return value.top();
}

int StackExecutor::numIslands(vector<vector<char>> &grid) {
    stack<pair<int,int>> temp_stack;
    int count = 0;
    int m = grid.size();
    int n = grid[0].size();
    char flag = '10';
    for (int row = 0; row < m; ++row) {
        for (int col = 0; col < n; ++col) {
            if (grid[row][col] == '1') {
                temp_stack.push({row, col});
                while (!temp_stack.empty()) {
                    auto [rowIndex, colIndex] = temp_stack.top();
                    temp_stack.pop();
                    for (vector<int> direction: directions) {
                        int r = rowIndex + direction[0];
                        int c = colIndex + direction[1];
                        if (r<0 || c < 0 || r>=m || c>=n || grid[r][c] == '0' || grid[r][c] == flag) {
                            continue;
                        }
                        grid[r][c] = flag;
                        temp_stack.push({r,c});
                    }
                }
                count ++;
            }
        }
    }
    return count;
}

Node *StackExecutor::cloneGraph(Node *node) {
    if (visited_map.count(node)) {
        return visited_map[node];
    }
    Node *ret = new Node(node->val);
    visited_map.emplace(node, ret);

    for (Node* n: node->neighbors) {
        ret->neighbors.push_back(cloneGraph(n));
    }

    return ret;
}

int StackExecutor::findTargetSumWays(vector<int> &nums, int target) {

    auto sum_nums = [](int num, int pre) -> int {
        return num + pre;
    };

    auto minus_nums = [](int num, int pre) -> int {
        return pre - num;
    };

    for(int num: nums) {
        
    }
    return 0;
}
