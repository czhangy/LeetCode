#include "errors.h"
#include <algorithm>

using namespace std;

// 671. Second Minimum Node In A Binary Tree - Easy - Tree
// -------------------------------------------------------------
// Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node.
// If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.
// More formally, the property root.val = min(root.left.val, root.right.val) always holds.
// Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.
// If no such second minimum value exists, output -1 instead.
// -------------------------------------------------------------
// Solve #3 | 09/11/20 | Time: 9:20 | Avg. Runtime: 0ms

// Given TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int findSecondMinimumValue(TreeNode *root) { // O(N) time, O(log N) space
    // Begin recursive call
    return helper(root, root->val);
}

// Maintain the root node's value
int helper(TreeNode *root, int val) {
    // Base case
    if (!root)
        return -1;
    // Return the first value that doesn't match the root
    if (root->val != val)
        return root->val;
    // Recursively check left and right subtrees
    int left = helper(root->left, val), right = helper(root->right, val);
    // If the left search fails
    if (left == -1)
        return right;
    // If the right search fails
    else if (right == -1)
        return left;
    // If both searches succeed, return the minimum of the 2 subtrees
    else
        return min(left, right);
}
