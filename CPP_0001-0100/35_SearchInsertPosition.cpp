#include "errors.h"
#include <vector>

using namespace std;

// 35. Search Insert Position - Easy - Array/Binary Search
// -------------------------------------------------------------
// Given a sorted array of distinct integers and a target value, return the index if the target is found.
// If not, return the index where it would be if it were inserted in order.
// -------------------------------------------------------------
// Solve #3 | 02/16/21 | Time: 3:09 | Avg. Runtime: 2.4ms

int searchInsert(vector<int> &nums, int target) { // O(log N) time, O(1) space
    // Initialize bounds
    int left = 0, right = nums.size() - 1;
    // Binary search
    while (left <= right) {
        // Calculate mid index, protecting against overflow
        int mid = left - (left - right) / 2;
        // Target found, return the index
        if (nums[mid] == target)
            return mid;
        // Value at mid index is greater than target --> move right bound left
        else if (nums[mid] > target)
            right = mid - 1;
        // Value at mid index is less than target --> move left bound right
        else
            left = mid + 1;
    }
    return left;
}
