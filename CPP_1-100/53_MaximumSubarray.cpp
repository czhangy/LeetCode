#include "errors.h"
#include <vector>

using namespace std;

// 53. Maximum Subarray - Easy - Array/Divide and Conquer/Dynamic Programming
// -------------------------------------------------------------
// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
// -------------------------------------------------------------
// Solve #2 | 06/30/20 | Time: 1:45 | Avg. Runtime: 20ms

int maxSubArray(vector<int> &nums) { // O(N) time, O(1) space
    // Catch empty vector edge case
    if (nums.empty())
        return 0;
    // Initialize
    int totalSum = nums[0], curSum = nums[0], size = nums.size();
    // Use dynamic programming through iteration
    for (int i = 1; i < size; i++) {
        curSum = max(curSum + nums[i], nums[i]);
        totalSum = max(curSum, totalSum);
    }
    return totalSum;
}
