#include "errors.h"

// 100. Same Tree - Easy - Tree/Depth-First Search
// -------------------------------------------------------------
// Given the roots of two binary trees p and q, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
// -------------------------------------------------------------
// Solve #1 | 06/30/20 | Time: 15:25 | Avg. Runtime: 0ms

// Given TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode *p, TreeNode *q) {
    // Catch p is an empty tree edge case
    if (!p)
        // Return whether or not q is also an empty tree
        return q;
    // If q is an empty tree or values don't match, return false
    if (!q || p->val != q->val)
        return false;
    // Recursively check left and right subtrees
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}