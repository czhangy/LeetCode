#include "errors.h"
#include <vector>

using namespace std;

// 283. Move Zeroes - Easy - Array/Two Pointers
// -------------------------------------------------------------
// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
// -------------------------------------------------------------
// Solve #1 | 07/17/20 | Time: 7:38 | Avg. Runtime: 12ms

void moveZeroes(vector<int> &nums) { // O(N) time, O(1) space
    // Initialize
    int numZeroes = 0, size = nums.size();
    // Iteratively count the number of 0s in nums
    for (int i = 0; i < size; i++)
        if (!nums[i])
            numZeroes++;
    // Set up vector manipulation
    int zeroStart = size - numZeroes, zeroes = 0;
    // Move non-zero elements
    for (int i = 0; i < size; i++) {
        // Update next index
        if (!nums[i])
            zeroes++;
        // Move the value
        else
            nums[i - zeroes] = nums[i];
    }
    // Fill the end with 0s
    for (int i = zeroStart; i < size; i++)
        nums[i] = 0;
}
