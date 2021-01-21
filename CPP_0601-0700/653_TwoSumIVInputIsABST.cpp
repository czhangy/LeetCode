#include "errors.h"
#include <unordered_set>

using namespace std;

// 653. Two Sum IV - Input Is A BST - Easy - Tree
// -------------------------------------------------------------
// Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.
// -------------------------------------------------------------
// Solve #1 | 08/24/20 | Time: 5:53 | Avg. Runtime: 63.8ms

// Given TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool findTarget(TreeNode *root, int k) { // O(N) time, O(log N) space
    // Initialize
    unordered_set<int> hash;
    // Begin recursive call
    return fillMap(root, hash, k);
}

bool fillMap(TreeNode *root, unordered_set<int> &m, int k) {
    // Base case
    if (!root)
        return false;
    // Complement the value found and search for it in the hash set
    if (m.count(k - root->val))
        return true;
    // Insert the current value into the hash set
    m.insert(root->val);
    // Recursively check subtrees
    return fillMap(root->left, m, k) || fillMap(root->right, m, k);
}
