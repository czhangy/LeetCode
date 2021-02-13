#include "errors.h"
#include <vector>

using namespace std;

// 78. Subsets - Medium - Array/Backtracking/Bit Manipulation
// -------------------------------------------------------------
// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.
// -------------------------------------------------------------
// Solve #3 | 02/12/21 | Time: 13:15 | Avg. Runtime: 1.6ms

// Recursive helper function to handle backtracking
void getSubsets(vector<int> cur, vector<int> &nums, vector<vector<int>> &res, int ind) {
    // Base case
    if (ind == nums.size())
        return;
    // Get current permutation and recurse
    cur.push_back(nums[ind]);
    res.push_back(cur);
    getSubsets(cur, nums, res, ind + 1);
    // Backtrack and recurse
    cur.pop_back();
    getSubsets(cur, nums, res, ind + 1);
}

vector<vector<int>> subsets(vector<int> &nums) { // O(2^N) time, O(N) space
    // Initialize
    vector<vector<int>> res;
    res.push_back({});
    // Begin recursion
    getSubsets({}, nums, res, 0);
    return res;
}
