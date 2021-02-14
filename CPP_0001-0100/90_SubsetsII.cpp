#include "errors.h"

// 90. Subsets II - Medium - Array/Backtracking
// -------------------------------------------------------------
// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets.
// Return the solution in any order.
// -------------------------------------------------------------
// Solve #2 | 02/13/21 | Time: 10:17 | Avg. Runtime: 4ms

// Recursive helper function for backtracking
void buildSubsets(vector<int> &nums, vector<int> cur, vector<vector<int> > &res, int ind) {
    // Base case
    if (ind == nums.size())
        return;
    // Initialize
    int temp = nums[ind];
    // Add the current value
    cur.push_back(nums[ind]);
    res.push_back(cur);
    buildSubsets(nums, cur, res, ind + 1);
    // Backtrack
    cur.pop_back();
    // Find the next unique value
    while (ind < nums.size() && nums[ind] == temp)
        ind++;
    buildSubsets(nums, cur, res, ind);
}

vector<vector<int> > subsetsWithDup(vector<int> &nums) { // O(2^N) time, O(N) space
    // Initialize
    vector<vector<int> > res;
    res.push_back({});
    // Sort to account for unique values
    sort(nums.begin(), nums.end());
    // Begin recursion
    buildSubsets(nums, {}, res, 0);
    return res;
}
