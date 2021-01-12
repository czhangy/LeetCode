#include "errors.h"

// 700. Search In A Binary Search Tree - Easy - Tree
// -------------------------------------------------------------
// Given the root node of a binary search tree (BST) and a value.
// You need to find the node in the BST that the node's value equals the given value.
// Return the subtree rooted with that node.
// If such node doesn't exist, you should return NULL.
// -------------------------------------------------------------
// Solve #1 | 08/31/20 | Time: 1:35 | Avg. Runtime: 94.4ms

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *searchBST(TreeNode *root, int val) { // O(log N) time, O(log N) space
    // Base case
    if (!root)
        return nullptr;
    // Target value found
    if (root->val == val)
        return root;
    // If current value is less than target, recursively search the left subtree
    if (val < root->val)
        return searchBST(root->left, val);
    // If current value is less than target, recursively search the right subtree
    else
        return searchBST(root->right, val);
}
