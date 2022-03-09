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

    //树的最大深度
    int maxDepth(TreeNode* root);

    //对称二叉树
    bool isSymmetric(TreeNode* root);

    bool isSymmetric(TreeNode* left, TreeNode* right);

    //最短路径
    bool hasPathSum(TreeNode* root, int targetSum);

    bool hasPathSum(TreeNode *node, int targetSum, int preValue);

    //106. 从中序与后序遍历序列构造二叉树
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);

    int root_position;
    unordered_map<int, int> visited_map;
    TreeNode *buildTree(int start, int end, vector<int> &inorder, vector<int> &postorder);

    //105. 从前序与中序遍历序列构造二叉树
    TreeNode* buildTreeByPreorder(vector<int>& preorder, vector<int>& inorder);
    TreeNode *buildTreeByPreorder(int start, int end, vector<int> &inorder, vector<int> &postorder);

    //116. 填充每个节点的下一个右侧节点指针
    TreeNode* connect(TreeNode* root);
};


#endif //ALGORITHM_TREEEXECUTOR_H
