#include "errors.h"
#include <vector>

using namespace std;

// 162. Find Peak Element - Medium - Array/Binary Search
// -------------------------------------------------------------
// A peak element is an element that is strictly greater than its neighbors.
// Given an integer array nums, find a peak element, and return its index.
// If the array contains multiple peaks, return the index to any of the peaks.
// You may imagine that nums[-1] = nums[n] = -∞.
// -------------------------------------------------------------
// Solve #2 | 05/16/20 | Time: N/A | Avg. Runtime: 9.6ms

int findPeakElement(vector<int> &nums) { // O(log N) time, O(1) space
    // Initialize
    int leftIndex = 0, rightIndex = nums.size() - 1;
    // Binary search
    while (leftIndex < rightIndex) {
        // Calculate mid index
        int midIndex = (leftIndex + rightIndex) / 2;
        // If subarray is increasing, search right subproblem
        if (nums[midIndex] < nums[midIndex + 1])
            leftIndex = midIndex + 1;
        // If subarray is decreasing, search left subproblem
        else
            rightIndex = midIndex;
    }
    return leftIndex;
}
