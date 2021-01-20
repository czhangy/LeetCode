#include "errors.h"
#include <vector>

using namespace std;

// 80. Remove Duplicates From Sorted Array II - Medium - Array/Two Pointers
// -------------------------------------------------------------
// Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
// Do not allocate extra space for another array; you must do this by modifying the input array in-place with O(1) extra memory.
// -------------------------------------------------------------
// Solve #1 | 01/19/21 | Time: 7:01 | Avg. Runtime: 3.2ms

int removeDuplicates(vector<int> &nums) { // O(N^2) time, O(1) space
    // Initialize second pointer
    int j = nums.size() - 1;
    // Iterate through valid subarray
    for (int i = 0; i < j - 1;) {
        // Illegal duplicate found
        if (nums[i] == nums[i + 1] && nums[i] == nums[i + 2]) {
            // Move duplicate out of valid bounds
            for (int k = i + 1; k < j; k++)
                swap(nums[k], nums[k + 1]);
            // Move valid bounds in
            j--;
        }
        else
            i++;
    }
    // Return new size
    return j + 1;
}
