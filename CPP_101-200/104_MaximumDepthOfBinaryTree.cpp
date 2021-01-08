#include "errors.h"
#include <algorithm>

using namespace std;

// 104. Maximum Depth Of Binary Tree - Easy - Tree/Depth-First Search
// -------------------------------------------------------------
// Given the root of a binary tree, return its maximum depth.
// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
// -------------------------------------------------------------
// Solve #1 | 07/01/20 | Time: 1:45 | Avg. Runtime: 13.6ms

// Given TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode *root) { // O(N) time, O(log N) space
    // Handle base case --> depth of a nullptr is 0
    if (!root)
        return 0;
    // Recursively call this function to find the maximum depth of the left or right subtree
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
