#include "errors.h"

// 897. Increasing Order Search Tree - Easy - Tree/Depth-First Search
// -------------------------------------------------------------
// Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.
// -------------------------------------------------------------
// Solve #3 | 12/23/20 | Time: 10:09 | Avg. Runtime: 1.6ms

// Given TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *increasingBST(TreeNode *root) { // O(N) time, O(log N) space
    // Leaf node found
    if (!root->left && !root->right)
        return root;
    // Get all prior nodes
    if (root->left)
        increasingBST(root->left)->right = root;
    // Append all following nodes
    if (root->right)
        root->right = increasingBST(root->right);
    return root;
}
