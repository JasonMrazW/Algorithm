//
// Created by bo on 2022/3/3.
//

#ifndef ALGORITHM_STACKEXECUTOR_H
#define ALGORITHM_STACKEXECUTOR_H
#include "../common.h"
#include <stack>
#include "Node.h"
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class StackExecutor: public IExecutor {
private:
    int left = 1;
    int right = 2;
    unordered_map<Node*, Node*> visited_map;
    int count = 0;
    stack<string> char_stack;
    vector<vector<int>> directions = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
    };
    unordered_map<int,int> visited;
public:
    StackExecutor():IExecutor() {

    }

    void execute() override;

    bool isValid(string s);

    //678：有效字符串
    bool checkValidString(string s);

    //038:温度
    vector<int> dailyTemperatures(vector<int>& temperatures);

    //150. 逆波兰表达式求值
    int evalRPN(vector<string>& tokens);

    //200. 岛屿数量
    int numIslands(vector<vector<char>>& grid);

    //133. 克隆图
    Node* cloneGraph(Node* node);

    //494. 目标和
    int findTargetSumWays(vector<int>& nums, int target);
    int findTargetSumWays2(vector<int>& nums, int target);

    int target_sum(vector<int> &nums, int target, int index, int sum);

    //94. 二叉树中序遍历
    vector<int> inorderTraversal(TreeNode* root);

    //394. 字符串解码
    string decodeString(string s);

    string decodeSubString(string s, int index);

    string decodeSubString2(string s, int index, int& end);

    //733. 图像渲染
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor);
    vector<vector<int>> floodFillDFS(vector<vector<int>>& image, int sr, int sc, int newColor);
};


#endif //ALGORITHM_STACKEXECUTOR_H
