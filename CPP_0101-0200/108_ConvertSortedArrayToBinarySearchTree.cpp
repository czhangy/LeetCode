#include "errors.h"
#include <vector>

using namespace std;

// 108. Convert Sorted Array To Binary Search Tree - Easy - Tree/Depth-First Search
// -------------------------------------------------------------
// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
// -------------------------------------------------------------
// Solve #2 | 02/16/21 | Time: 12:51 | Avg. Runtime: 16ms

// Given TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive helper function
TreeNode *buildSubtree(vector<int> &nums, int left, int right) {
    // Base case
    if (left >= right)
        return nullptr;
    // Calculate the middle index --> root of the subtree
    int mid = (left + right) / 2;
    // Build the root and its left and right subtrees
    TreeNode *root = new TreeNode(nums[mid], buildSubtree(nums, left, mid), buildSubtree(nums, mid + 1, right));
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums) { // O(N) time, O(log N) space
    // Begin recursion
    return buildSubtree(nums, 0, nums.size());
}
