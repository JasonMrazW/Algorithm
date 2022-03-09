//
// Created by bo on 2022/3/9.
//

#ifndef ALGORITHM_TREENODE_H
#define ALGORITHM_TREENODE_H
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};
#endif //ALGORITHM_TREENODE_H
