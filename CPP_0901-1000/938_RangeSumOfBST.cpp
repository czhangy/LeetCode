#include "errors.h"

// 938. Range Sum Of BST - Easy - Tree/Recursion
// -------------------------------------------------------------
// Given the root node of a binary search tree, return the sum of values of all nodes with a value in the range [low, high].
// -------------------------------------------------------------
// Solve #1 | 09/29/20 | Time: 4:01 | Avg. Runtime: 176ms

// Given TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int rangeSumBST(TreeNode *root, int L, int R) { // O(N) time, O(log N) space
    // Base case
    if (!root)
        return 0;
    // Set the sum if the current value is in-bounds
    int sum = root->val >= L && root->val <= R ? root->val : 0;
    // Recursively check the right subtree if the current value is too small
    if (root->val < L)
        sum += rangeSumBST(root->right, L, R);
    // Recursively check the left subtree if the current value is too large
    else if (root->val > R)
        sum += rangeSumBST(root->left, L, R);
    // Recursively check both subtrees if the current value is in-bounds
    else
        sum += rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    return sum;
}
