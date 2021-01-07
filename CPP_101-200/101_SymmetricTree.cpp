#include errors.h

// 101. Symmetric Tree - Easy - Tree/Depth-First Search/Breadth-First Search
// -------------------------------------------------------------
// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
// -------------------------------------------------------------
// Solve #2 | 7/3/20 | Time: 2:26 | Avg. Runtime: 12.8ms

bool isSymmetric(TreeNode *root) { // O(log N) time, O(log N) space
    // Handle base case
    if (!root)
        return true;
    // Begin recursion
    return helperFunc(root->left, root->right);
}

// Recursive Function
bool helperFunc(TreeNode *left, TreeNode *right) {
    // Leaf node found --> symmetric base case
    if (!left && !right)
        return true;
    // Only one child --> not symmetric by definition
    if (!left || !right)
        return false;
    // Check for symmetry of value and symmetry of subtrees through recursive calls
    return (left->val == right->val) && helperFunc(left->left, right->right) && helperFunc(left->right, right->left);
}