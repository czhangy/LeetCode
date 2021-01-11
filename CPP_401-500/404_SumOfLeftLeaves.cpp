#include "errors.h"

// 404. Sum Of Left Leaves - Easy - Tree
// -------------------------------------------------------------
// Find the sum of all left leaves in a given binary tree.
// -------------------------------------------------------------
// Solve #1 | 07/27/20 | Time: 6:04 | Avg. Runtime: 3.2ms

// Given TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int sumOfLeftLeaves(TreeNode *root) { // O(N) time, O(log N) space
    // Base case
    if (!root)
        return 0;
    // Recursively get the sum of left leaves of the left and right subtrees + a left leaf if possible
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right) + (root->left && !root->left->left && !root->left->right ? root->left->val : 0);
}
