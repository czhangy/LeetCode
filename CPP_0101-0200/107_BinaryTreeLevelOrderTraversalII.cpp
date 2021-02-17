#include "errors.h"
#include <vector>

using namespace std;

// 107. Binary Tree Level Order Traversal II - Easy - Tree/Breadth-First Search
// -------------------------------------------------------------
//
// -------------------------------------------------------------
// Solve #2 | 02/16/21 | Time: 8:46 | Avg. Runtime: 4ms

// Given TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Helper recursive function
void traverse(vector<vector<int>> &res, TreeNode *root, int ind) {
    // Base case
    if (!root)
        return;
    // Grow res if needed
    if (ind + 1 > res.size())
        res.push_back({});
    // Push current value into corresponding level
    res[ind].push_back(root->val);
    // Traverse subtrees
    traverse(res, root->left, ind + 1);
    traverse(res, root->right, ind + 1);
}

vector<vector<int>> levelOrderBottom(TreeNode *root) { // O(N) time, O(log N) space
    // Intialize
    vector<vector<int>> res;
    // Begin recursion
    traverse(res, root, 0);
    // Transform to bottom-up representation
    reverse(res.begin(), res.end());
    return res;
}
