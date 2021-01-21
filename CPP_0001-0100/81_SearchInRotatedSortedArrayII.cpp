#include "errors.h"
#include <vector>

using namespace std;

// 81. Search In Rotated Sorted Array II - Medium - Array/Binary Search
// -------------------------------------------------------------
// You are given an integer array nums sorted in ascending order (not necessarily distinct values), and an integer target.
// Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,4,4,5,6,6,7] might become [4,5,6,6,7,0,1,2,4,4]).
// Return whether or not target is in the array.
// -------------------------------------------------------------
// Solve #1 | 01/20/21 | Time: 22:02 | Avg. Runtime: 5.6ms

bool search(vector<int> &nums, int target) { // O(log N) time, O(1) space
    // Intialize bounds
    int left = 0, right = nums.size() - 1;
    // Binary search
    while (left <= right) {
        // Calculate mid index, protecting against overflow
        int mid = left - ((left - right) >> 1);
        // If target found
        if (nums[mid] == target)
            return true;
        // If the left subarray is not pivoted
        if (nums[left] < nums[mid]) {
            // If the target may be in the left subarray
            if (target >= nums[left] && nums[mid] > target)
                right = mid - 1;
            // Reduce bounds to right subarray
            else
                left = mid + 1;
        }
        // Handle duplicates edge case
        else if (nums[left] == nums[mid])
            left++;
        else {
            // If the target may be in the right subarray
            if (target > nums[mid] && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    // Target not found
    return false;
}
