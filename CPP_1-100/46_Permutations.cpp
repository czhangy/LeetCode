#include "errors.h"
#include <algorithm>
#include <vector>

using namespace std;

// 46. Permutations - Medium - Backtracking
// -------------------------------------------------------------
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
// -------------------------------------------------------------
// Solve #1 | 10/03/20 | Time: 18:09 | Avg. Runtime: 2.4ms

vector<vector<int>> permute(vector<int> &nums) { // O(N!) time, O(N!) space
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
        int index = -1, minIndex = -1;
        // Get latest increasing index
        for (int i = 0; i < size - 1; i++)
            if (nums[i] < nums[i + 1])
                index = i;
        // If vector is monotonically decreasing, loop permutation
        if (index == -1)
            reverse(nums.begin(), nums.end());
        else {
            // Get the index of the smallest number that's greater than the pivot
            for (int i = index + 1; i < size; i++)
                if (nums[i] > nums[index] && (minIndex == -1 || nums[i] < nums[minIndex]))
                    minIndex = i;
            // Swap pivot and small number
            swap(nums[index], nums[minIndex]);
            // Sort rest of vector
            sort(nums.begin() + index + 1, nums.end());
        }
        // Insert new permutation
        res.push_back(nums);
    // Check for loop-around
    } while (nums != res[0]);
    // Adjust for conditional pushing back duplicate of initial condition
    res.pop_back();
    return res;
}
