#include "errors.h"

// 226. Invert Binary Tree - Easy - Tree
// -------------------------------------------------------------
// Invert a binary tree.
// -------------------------------------------------------------
// Solve #1 | 07/13/20 | Time: 3:51 | Avg. Runtime: 4ms

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *invertTree(TreeNode *root) { // O(N) time, O(log N) space
    // Catch empty tree edge case
    if (!root)
        return nullptr;
    // Recursively invert left subtree
    TreeNode *temp = invertTree(root->left);
    // Recursively invert right subtree
    root->left = invertTree(root->right);
    root->right = temp;
    return root;
}
