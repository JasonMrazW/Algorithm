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

int TreeExecutor::maxDepth(TreeNode *root) {
    if (!root) {
        return 0;
    }

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left, right) + 1;
}

bool TreeExecutor::isSymmetric(TreeNode *root) {
    if (root == nullptr) {
        return false;
    }

    return isSymmetric(root->left, root->right);
}

bool TreeExecutor::isSymmetric(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr) {
        return true;
    }

    if (left == nullptr || right == nullptr) {
        return false;
    }

    if (left->val != right->val) {
        return false;
    }

    return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}

bool TreeExecutor::hasPathSum(TreeNode *node, int targetSum, int preValue) {
    if (node == nullptr)
        return false;
    //叶子节点
    int current_value = preValue + node->val;
    if (node->left == nullptr && node->right == nullptr) {
        return current_value == targetSum;
    }

    return hasPathSum(node->left, targetSum, current_value) ||
    hasPathSum(node->right, targetSum, current_value);
}

bool TreeExecutor::hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
        return false;
    }

    return hasPathSum(root, targetSum, 0);
}

TreeNode *TreeExecutor::buildTree(vector<int> &inorder, vector<int> &postorder) {

    int index = 0;
    for (int order: inorder) {
        visited_map[order] = index++;
    }
    root_position = (int)postorder.size()-1;
    return buildTree(0, root_position, inorder, postorder);
}

TreeNode *TreeExecutor::buildTree(int in_start, int in_end, vector<int> &inorder, vector<int> &postorder) {
    if (in_start > in_end) {
        return nullptr;
    }

    int root_val = postorder[root_position];

    TreeNode *root = new TreeNode(root_val);
    //find 中序数组中对应的位置
    int in_index = inorder[root_val];

    root_position--;
    root->right = buildTree(in_index + 1, in_end, inorder, postorder);
    root->left = buildTree(in_start, in_index -1, inorder, postorder);

    return root;
}


