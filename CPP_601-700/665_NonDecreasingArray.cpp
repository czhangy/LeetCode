#include "errors.h"
#include <vector>

using namespace std;

// 665. Non-Decreasing Array - Easy - Array
// -------------------------------------------------------------
// Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.
// We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).
// -------------------------------------------------------------
// Solve #2 | 09/03/20 | Time: 8:59 | Avg. Runtime: 57.6ms

bool checkPossibility(vector<int> &nums) { // O(N) time, O(1) space
    // Initialize
    int size = nums.size(), count = 0, minVal = INT_MIN;
    // Iterate through vector
    for (int i = 0; i < size - 1; i++) {
        // If current pairing is decreasing
        if (nums[i] > nums[i + 1]) {
            // Modify array so that it is now non-decreasing
            count++;
            nums[i] = minVal;
            i--;
        } else
            // If sequentially valid, update the minimum possible value to maintain non-decreasing sequence
            minVal = max(nums[i], minVal);
        // If more than 1 change, failure condition reached
        if (count > 1)
            return false;
    }
    return true;
}
