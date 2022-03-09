//
// Created by bo on 2022/3/9.
//

#ifndef ALGORITHM_TREENODE_H
#define ALGORITHM_TREENODE_H
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode(): val(0), left(nullptr), right(nullptr), next(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr),next(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right),next(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right, TreeNode *next): val(x), left(left), right(right),next(next) {}
};
#endif //ALGORITHM_TREENODE_H
