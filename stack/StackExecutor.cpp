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
    if (nums.empty()) {
        return -1;
    }
    stack<int> sum_stack;
    sum_stack.push(0);
    stack<int> sum_stack2;

    int size = 0;
    stack<int> *p = nullptr;
    stack<int> *p2 = nullptr;
    for (int i = 0; i < nums.size(); ++i) {
        if (i % 2 == 0) {
            p = &sum_stack;
            p2 = &sum_stack2;
        } else {
            p = &sum_stack2;
            p2 = &sum_stack;
        }

        while (!p->empty()) {
            int top = p->top();
            p->pop();
            int sum_value = top + nums[i];
            int min_value = top - nums[i];
            p2->push(sum_value);
            p2->push(min_value);
        }
    }

    int count = 0;
    while (!p2->empty()) {
        int top = p2->top();
        p2->pop();
        if (top == target) {
            count++;
        }
    }

    return count;
}

int StackExecutor::target_sum(vector<int> &nums, int target, int index, int sum) {
    if (index == nums.size()) {
        if (sum == target) {
            count++;
        }
    } else {
        target_sum(nums, target, index+1, sum + nums[index]);
        target_sum(nums, target, index+1, sum - nums[index]);
    }
}

int StackExecutor::findTargetSumWays2(vector<int> &nums, int target) {
    target_sum(nums, target, 0 ,0);
    return count;
}

vector<int> StackExecutor::inorderTraversal(TreeNode *root) {
    vector<int> ret;
    if (root == nullptr) return ret;
    stack<TreeNode*> temp;
    TreeNode *cur = root;

    while (cur != nullptr || !temp.empty()) {
        while (cur != nullptr) {
            temp.push(cur);
            cur = cur->left;
        }

        if (!temp.empty()) {
            TreeNode* top = temp.top();
            temp.pop();
            ret.push_back(top->val);
            cur = top->right;
        }
    }

    return ret;
}

string StackExecutor::decodeString(string s) {
    int end = 0;
    return decodeSubString2(s, 0, end);
}

string StackExecutor::decodeSubString2(string s, int index, int& end) {
    int i = index;
    int num = 0;
    string ret = "";
    while (i < s.length()) {
        char c = s[i];
        if (isdigit(c)) {
            int n = 0;
            while (isdigit(c)) {
                num = num * 10 + (c - '0');
                i++;
                c = s[i];
                n++;
            }
        } else if (c == '[') {
            int end = 0;
            string tmp = decodeSubString2(s, i+1,end);
            i = end + 1;
            while (num > 0) {
                ret.append(tmp);
                num--;
            }
        } else if (c == ']') {
            end = i;
            return ret;
        } else {
            ret.append(1, c);
            i++;
        }
    }
    return ret;
}

string StackExecutor::decodeSubString(string s, int index) {
    int i = index;
    queue<string> temp_queue;
    stack<string> char_stack;
    while (i < s.length()) {
        char c = s[i];
        if (isdigit(c)) {
            int num = 0;
            int n = 0;
            while (isdigit(c)) {
                num = num * 10 + (c - '0');
                i++;
                c = s[i];
                n++;
            }
            char_stack.push(to_string(num));
        } else if (c == ']') {
            if (char_stack.empty()) {
                //invalid string
                return "";
            }

            string tmp = char_stack.top();
            char_stack.pop();
            vector<string> tmp_vector;
            while (tmp != "[") {
                tmp_vector.push_back(tmp);
                tmp = char_stack.top();
                char_stack.pop();
            }

            reverse(tmp_vector.begin(),tmp_vector.end());

            string ret = "";
            int k = 0;
            while (k < tmp_vector.size()) {
                ret.append(tmp_vector[k++]);
            }

            string ret_tmp = "";

            int num = atoi(char_stack.top().c_str());
            cout << char_stack.top() << endl;
            char_stack.pop();
            while (num > 0) {
                ret_tmp.append(ret);
                num--;
            }
            i++;
            char_stack.push(ret_tmp);
        } else {
            char_stack.push(string(1, c));
            i++;
        }
    }

    stack<string> tmp_stack;
    while (!char_stack.empty()) {
        tmp_stack.push(char_stack.top());
        char_stack.pop();
    }

    string ret = "";
    while (!tmp_stack.empty()) {
        ret.append(tmp_stack.top());
        tmp_stack.pop();
    }
    return ret;
}
vector<vector<int>> StackExecutor::floodFillDFS(vector<vector<int>> &image, int sr, int sc, int newColor) {
    int source_value = image[sr][sc];
    stack<pair<int,int>> pos_stack;
    pos_stack.push({sr, sc});

    int row_size = image.size();
    int col_size = image[0].size();
    image[sr][sc] = newColor;

    while (!pos_stack.empty()) {
        auto [row, col] = pos_stack.top();
        pos_stack.pop();
        visited.emplace(row*1000+col, col);
        image[row][col] = newColor;

        for (int i = 0; i < directions.size(); ++i) {
            int rowIndex = row + directions[i][0];
            int colIndex = col + directions[i][1];
            if (rowIndex >= row_size || rowIndex < 0 || colIndex >= col_size ||
            colIndex < 0 || image[rowIndex][colIndex] != source_value ||
            visited.count(rowIndex*1000 + colIndex)) {
                continue;
            }
            floodFillDFS(image, rowIndex, colIndex, newColor);
        }
    }
    return image;
}
vector<vector<int>> StackExecutor::floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    int source_value = image[sr][sc];
    queue<pair<int,int>> pos_queue;
    pos_queue.push({sr, sc});

    int row_size = image.size();
    int col_size = image[0].size();
    image[sr][sc] = newColor;
    unordered_map<int,int> visited;

    while (!pos_queue.empty()) {
        auto [row, col] = pos_queue.front();
        pos_queue.pop();
        for (int i = 0; i < directions.size(); ++i) {
            int rowIndex = row + directions[i][0];
            int colIndex = col + directions[i][1];
            if (rowIndex >= row_size || rowIndex < 0 || colIndex >= col_size ||
            colIndex < 0 || image[rowIndex][colIndex] != source_value ||
            visited.count(rowIndex*1000 + colIndex)) {
                continue;
            }
            image[rowIndex][colIndex] = newColor;
            visited.emplace(rowIndex*1000+colIndex, colIndex);
            pos_queue.push({rowIndex, colIndex});
        }
    }

    return image;
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

    //vector<vector<char>> queue = {{'1','1','0','0','0'}, {'1','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','1'}};
    //        cout << "land count :" << numIslands(queue) << endl;

    //vector<int> numbs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
    //int target = 1;
    //cout << findTargetSumWays2(numbs, target) << endl;

    cout << decodeString("ab3[ab3[a]]b") << endl;

    vector<vector<int>> queue = {{0}, {1}};
//    vector<vector<int>> queue2 = floodFillDFS(queue, 1,1,2);
vector<vector<int>> queue2 = updateMatrix(queue);
    cout << "xxx" << endl;
}

vector<vector<int>> StackExecutor::updateMatrix(vector<vector<int>> &mat) {
    //初始化相同大小的矩阵
    vector<vector<int>> ret(mat.size(), vector<int>(mat[0].size()));

    queue<pair<int,int>> tmp_queue;
    int row_size = mat.size();
    int col_size = mat[0].size();
    vector<vector<int>> visited(row_size, vector<int>(col_size));

    for (int i = 0; i < row_size; ++i) {
        for (int j = 0; j < col_size; ++j) {
            if (mat[i][j] == 0) {
                tmp_queue.push({i,j});
                visited[i][j] = 1;
            }
        }
    }


    int step = 0;
    while (!tmp_queue.empty()) {
        auto [row, col] = tmp_queue.front();
        tmp_queue.pop();

        for (int i = 0; i < 4; ++i) {
            int rowIndex = row + directions[i][0];
            int colIndex = col + directions[i][1];
            if (rowIndex >= row_size || rowIndex < 0 || colIndex >= col_size ||
            colIndex < 0 || visited[rowIndex][colIndex]) {
                continue;
            }

            ret[rowIndex][colIndex] = ret[row][col] + 1;
            visited[rowIndex][colIndex] = 1;
            tmp_queue.emplace(rowIndex,colIndex);
        }
    }

    return ret;
}


