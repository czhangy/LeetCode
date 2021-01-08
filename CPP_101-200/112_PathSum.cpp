#include "errors.h"

// 112. Path Sum - Easy - Tree/Depth-First Search
// -------------------------------------------------------------
// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
// -------------------------------------------------------------
// Solve #1 | 07/04/20 | Time: 5:12 | Avg. Runtime: 25.6ms

// Given TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool hasPathSum(TreeNode *root, int sum) { // O(N) time, O(log N) space
    // Handle base case
    if (!root)
        return false;
    // Leaf node reached and sum is correct
    if (root->val == sum && !root->left && !root->right)
        return true;
    // Modify sum to reflect current node's value
    sum -= root->val;
    // Recursively continue down subtrees
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}
