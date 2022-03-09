//
// Created by bo on 2022/3/9.
//

#ifndef ALGORITHM_TREEEXECUTOR_H
#define ALGORITHM_TREEEXECUTOR_H
#include "../common.h"
#include "TreeNode.h"
using namespace std;

class TreeExecutor : public IExecutor{
public:
    TreeExecutor():IExecutor() {}

    //前序遍历
    vector<int> preorderTraversal(TreeNode* root);

    //前序遍历迭代实现
    vector<int> preorderTraversalByIterator(TreeNode* root);

    void preorderTraversal(TreeNode* node, vector<int> &visited);

    //后续遍历
    vector<int> postorderTraversal(TreeNode* root);

    vector<int> postorderTraversalByIterator(TreeNode* root);

    void postorderTraversal(TreeNode* node, vector<int> &visited);

    //层序遍历
    vector<vector<int>> levelOrder(TreeNode* root);

    void levelOrder(TreeNode *root, vector<vector<int>> &visited, int step);
};


#endif //ALGORITHM_TREEEXECUTOR_H
