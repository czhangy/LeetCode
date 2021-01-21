#include "errors.h"

// 669. Trim A Binary Search Tree - Easy - Tree
// -------------------------------------------------------------
// Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high].
// Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant).
// It can be proven that there is a unique answer.
// Return the root of the trimmed binary search tree.
// Note that the root may change depending on the given bounds.
// -------------------------------------------------------------
// Solve #1 | 08/26/20 | Time: 7:16 | Avg. Runtime: 18.4ms

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *trimBST(TreeNode *root, int L, int R) { // O(N) time, O(log N) space
    // Base case
    if (!root)
        return nullptr;
    // Fix subtrees
    if (root->left)
        root->left = trimBST(root->left, L, R);
    if (root->right)
        root->right = trimBST(root->right, L, R);
    // Trim current root
    if (root->val > R || root->val < L) {
        // Reassign if possible
        if (root->left)
            root = root->left;
        else if (root->right)
            root = root->right;
        else
            root = nullptr;
    }
    return root;
}
