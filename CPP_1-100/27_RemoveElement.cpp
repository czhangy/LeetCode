#include "errors.h"
#include <vector>

using namespace std;

// 27. Remove Element - Easy - Array/Two Pointers
// -------------------------------------------------------------
// Given an array nums and a value val, remove all instances of that value in-place and return the new length.
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
// The order of elements can be changed.
// It doesn't matter what you leave beyond the new length.
// -------------------------------------------------------------
// Solve #1 | 06/27/20 | Time: 2:07 | Avg. Runtime: 2.4ms

int removeElement(vector<int> &nums, int val) { // O(N) time, O(1) space
    // Initialize
    int size = nums.size();
    int count = 0;
    // Iterate through vector
    for (int i = 0; i < size; i++) {
        // Increment count when target value found
        if (nums[i] == val)
            count++;
        // Modify array by rewriting non-target values to target values
        else
            nums[i - count] = nums[i];
    }
    // Return new "length"
    return size - count;
}
