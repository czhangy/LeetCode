#include "errors.h"
#include <algorithm>
#include <vector>

using namespace std;

// 31. Next Permutation - Medium - Array
// -------------------------------------------------------------
// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
// If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
// The replacement must be in place and use only constant extra memory.
// -------------------------------------------------------------
// Solve #1 | 09/28/20 | Time: 30:12 | Avg. Runtime: 4ms

void nextPermutation(vector<int> &nums) { // O(N) time, O(1) space
    // Initialize --> use -3 as a flag to adjust for all edge cases
    int index = -3, size = nums.size(); 
    // Get pivot index
    for (int i = 0; i < size - 1; i++)
        if (nums[i] < nums[i + 1])
            index = i;
    // Catch end of list edge case
    if (index == size - 2)
        swap(nums[index], nums[index + 1]);
    // Common case
    else if (index != -3) {
        int lowInd = index + 1;
        // Find next lowest value that's greater than pivot
        for (int i = index + 2; i < size; i++)
            if (nums[i] > nums[index] && nums[i] < nums[lowInd])
                lowInd = i;
        // Generate next permutation
        swap(nums[index], nums[lowInd]);
        // Sort rest of vector
        sort(nums.begin() + index + 1, nums.end());
    // Catch wrap around edge case
    } else
        // Highest permutation is reverse ordered, lowest permutation is in order      
        reverse(nums.begin(), nums.end());
}
