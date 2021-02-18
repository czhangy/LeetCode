#include <algorithm>

using namespace std;

// 111. Minimum Depth Of Binary Tree - Easy - Tree/Depth-First Search/Breadth-First Search
// -------------------------------------------------------------
// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
// -------------------------------------------------------------
// Solve #2 | 02/17/21 | Time: 3:47 | Avg. Runtime: 225.6ms

// Given TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int minDepth(TreeNode *root) { // O(N) time, O(log N) space
    // Handle empty tree edge case
    if (!root)
        return 0;
    // Leaf node found
    if (!root->left && !root->right)
        return 1;
    // Initialize
    int left = INT_MAX, right = INT_MAX;
    // Check left subtree if it exists
    if (root->left)
        left = minDepth(root->left);
    // Check right subtree if it exists
    if (root->right)
        right = minDepth(root->right);
    // Use the minimum depth found so far
    return min(left, right) + 1;
}
