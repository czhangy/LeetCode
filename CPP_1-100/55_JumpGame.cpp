#include "errors.h"
#include <vector>

using namespace std;

// 55. Jump Game - Medium - Array/Greedy
// -------------------------------------------------------------
// Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Determine if you are able to reach the last index.
// -------------------------------------------------------------
// Solve #3 | 01/15/21 | Time: 2:05 | Avg. Runtime: 7.2ms

bool canJump(vector<int> &nums) { // O(N) time, O(1_ space)
    // Initialize
    int size = nums.size(), i = 0;
    // Iterate through the array
    for (int r = 0; i < size && i <= r; i++)
        // Mark the furthest reachable point
        r = max(i + nums[i], r);
    // Return if we reached the end of the array
    return i == size;
}
