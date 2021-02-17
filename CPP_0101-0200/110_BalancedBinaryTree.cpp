#include "errors.h"
#include <algorithm>

using namespace std;

// 110. Balanced Binary Tree - Easy - Tree/Depth-First Search/Recursion
// -------------------------------------------------------------
// Given a binary tree, determine if it is height-balanced.
// For this problem, a height-balanced binary tree is defined as:
// - a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
// -------------------------------------------------------------
// Solve #2 | 02/16/21 | Time: 12:19 | Avg. Runtime: 9.6ms

// Given TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive helper function
int getDepth(TreeNode *root, bool &res) {
    // Base cases
    if (!root || !res)
        return 0;
    // Get height of left and right subtrees
    int left = getDepth(root->left, res), right = getDepth(root->right, res);
    // Use the definition of balanced BST to set res appropriately
    if (abs(left - right) > 1)
        res = false;
    // Account for the worst-case scenario
    return max(left, right) + 1;
}

bool isBalanced(TreeNode *root) { // O(N) time, O(log N) space
    // Initialize
    bool res = true;
    // Begin recursion
    getDepth(root, res);
    return res;
}
