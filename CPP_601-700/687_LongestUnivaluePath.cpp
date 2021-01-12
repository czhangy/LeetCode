#include "errors.h"
#include <algorithm>

using namespace std;

// 687. Longest Univalue Path - Medium - Tree/Recursion
// -------------------------------------------------------------
// Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value.
// This path may or may not pass through the root.
// The length of the path between two nodes is represented by the number of edges between them.
// -------------------------------------------------------------
// Solve #4 | 09/19/20 | Time: 4:16 | Avg. Runtime: 187.2ms

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int longestUnivaluePath(TreeNode *root) { // O(N) time, O(1) space
    // Initialize
    int path = 0;
    // Catch empty tree edge case
    if (root)
        // Begin recursive call
        traverse(root, path);
    return path;
}

int traverse(TreeNode *root, int &path) {
    // Find longest path in left subtree
    int left = root->left ? traverse(root->left, path) : 0;
    // Find longest path in right subtree
    int right = root->right ? traverse(root->right, path) : 0;
    // Account for parent node
    int resl = root->left && root->left->val == root->val ? left + 1 : 0;
    int resr = root->right && root->right->val == root->val ? right + 1 : 0;
    // Update path
    path = max(path, resl + resr);
    // Remove branching
    return max(resl, resr);
}
