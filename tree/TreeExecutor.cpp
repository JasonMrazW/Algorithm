//
// Created by bo on 2022/3/9.
//

#include "TreeExecutor.h"

vector<int> TreeExecutor::preorderTraversal(TreeNode *root) {
    vector<int> ret;
    if (root) {
        preorderTraversal(root, ret);
    }
    return ret;
}

void TreeExecutor::preorderTraversal(TreeNode *node, vector<int> &visited) {
    visited.push_back(node->val);
    if (node->left != nullptr) {
        preorderTraversal(node->left, visited);
    }
    if (node->right != nullptr) {
        preorderTraversal(node->right, visited);
    }
}

vector<int> TreeExecutor::preorderTraversalByIterator(TreeNode *root) {
    vector<int> ret;
    if (root == nullptr) {
        return ret;
    }
    stack<TreeNode*> node_stack;
    node_stack.emplace(root);
    while (!node_stack.empty()) {
        TreeNode* cur = node_stack.top();
        node_stack.pop();
        ret.push_back(cur->val);
        if (cur->right) {
            node_stack.push(cur->right);
        }
        if (cur->left) {
            node_stack.push(cur->left);
        }
    }

    return ret;
}

vector<int> TreeExecutor::postorderTraversal(TreeNode *root) {
    vector<int> ret;
    if (root) {
        postorderTraversal(root, ret);
    }
    return ret;
}

void TreeExecutor::postorderTraversal(TreeNode *node, vector<int> &visited) {
    if (node->left) {
        postorderTraversal(node, visited);
    }
    if (node->right) {
        postorderTraversal(node, visited);
    }
    visited.push_back(node->val);
}

vector<int> TreeExecutor::postorderTraversalByIterator(TreeNode *root) {
    vector<int> ret;
    if (root == nullptr) {
        return ret;
    }

    stack<TreeNode*> node_stack;
    node_stack.push(root);
    unordered_set<TreeNode*> visited;

    while (!node_stack.empty()) {
        TreeNode *cur = node_stack.top();
        //叶子节点
        if ((cur->left == nullptr && cur->right == nullptr) ||
         visited.count(cur->left)||
         visited.count(cur->right)) {
            ret.push_back(cur->val);
            node_stack.pop();
            visited.emplace(cur);
        } else {
            if (cur->right) {
                node_stack.push(cur->right);
            }
            if (cur->left) {
                node_stack.push(cur->left);
            }
        }
    }
    return ret;

}

vector<vector<int>> TreeExecutor::levelOrder(TreeNode *root) {
    vector<vector<int>> ret;
    if (root) {
        levelOrder(root, ret, 0);
    }
    return ret;
}

void TreeExecutor::levelOrder(TreeNode *root, vector<vector<int>> &visited, int step) {
    while (visited.size() <= step) {
        vector<int> v;
        visited.emplace_back(vector<int>());
    }
    visited[step].push_back(root->val);
    if (root->left) {
        levelOrder(root->left, visited, step+1);
    }
    if (root->right) {
        levelOrder(root->right, visited, step+1);
    }
}


