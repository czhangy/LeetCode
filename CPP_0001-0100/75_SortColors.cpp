#include "errors.h"
#include <vector>

using namespace std;

// 75. Sort Colors - Medium - Array/Two Pointers/Sort
// -------------------------------------------------------------
// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// -------------------------------------------------------------
// Solve #1 | 01/18/21 | Time: 28:34 | Avg. Runtime: 2.4ms

void sortColors(vector<int> &nums) { // O(N) time, O(1) space
    // Initialize
    int size = nums.size(), val = 0;
    // Iterate through the vector
    for (int i = 0; i < size; i++) {
        // If current index is the correct value, iterate forwards
        if (nums[i] == val)
            continue;
        // Incorrect value, needs to swap
        else {
            // Initialize second pointer
            int j;
            // Check the subarray beyond the current index
            for (j = i; j < size; j++)
                // Desired value found, perform swap and move on
                if (nums[j] == val) {
                    swap(nums[i], nums[j]);
                    break;
                }
            // No more of desired value, increment desired value and recheck current index
            if (j == size && !val) {
                val++;
                i--;
            }
            // 0s and 1s have been set, end of iteration
            else if (j == size)
                break;
        }
    }
}
