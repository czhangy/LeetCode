#include "errors.h"
#include <vector>

using namespace std;

// 47. Permutations II - Medium - Backtracking
// -------------------------------------------------------------
// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
// -------------------------------------------------------------
// Solve #1 | 10/03/20 | Time: 8:30 | Avg. Runtime: 6.4ms

vector<vector<int>> permuteUnique(vector<int> &nums) { // O(N!) time, O(N!) space
    // Initialize
    vector<vector<int>> res;
    res.push_back(nums);
    int size = nums.size();
    // Catch empty vector and size-1 vector edge cases
    if (size <= 1)
        return res;
    // Perform loop once for easy conditional check
    do {
        // Initialize
        int i, j;
        // Get pivot index
        for (i = size - 2; i >= 0; i--)
            if (nums[i + 1] > nums[i])
                break;
        // Vector is monotonically decreasing, loop to first permutation
        if (i < 0)
            reverse(nums.begin(), nums.end());
        else {
            for (j = size - 1; j > i; j--)
                // Low is guaranteed to be the rightmost digit that's greater than the pivot
                if (nums[j] > nums[i]) 
                    break;
            // Swap pivot and low
            swap(nums[i], nums[j]);
            // nums is guaranteed to be in decreasing order after pivot, reverse == sort
            reverse(nums.begin() + i + 1, nums.end());
        }
        res.push_back(nums);
    // Check for loop-around
    } while (nums != res[0]);
    // Adjust for duplicate of initial entry
    res.pop_back();
    return res;
}
