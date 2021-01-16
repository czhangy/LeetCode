#include "errors.h"

// 965. Univalued Binary Tree - Easy - Tree
// -------------------------------------------------------------
// A binary tree is univalued if every node in the tree has the same value.
// Return true if and only if the given tree is univalued.
// -------------------------------------------------------------
// Solve #1 | 12/23/20 | Time: 2:34 | Avg. Runtime: 2.4ms

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Use a helper function to track the value of the root node
bool helperFunc(TreeNode *root, int val) {
    // Base case
    if (!root)
        return true;
    // Different value found
    if (val != root->val)
        return false;
    // Recursively check the left and right subtrees
    return helperFunc(root->left, val) && helperFunc(root->right, val);
} 
bool isUnivalTree(TreeNode *root) { // O(N) time, O(log N) space
    // Begin recursive call
    return helperFunc(root, root->val);
}