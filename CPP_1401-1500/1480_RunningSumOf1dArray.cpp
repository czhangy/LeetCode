#include "errors.h"
#include <vector>

using namespace std;

// 1480. Running Sum Of 1d Array - Easy - Array
// -------------------------------------------------------------
// Given an array nums.
// We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
// Return the running sum of nums.
// -------------------------------------------------------------
// Solve #1 | 09/22/20 | Time: 3:04 | Avg. Runtime: 4ms

vector<int> runningSum(vector<int> &nums) { // O(N) time, O(N) space
    // Initialize
    int size = nums.size();
    vector<int> sums(size);
    // Set the initial running sum
    sums[0] = nums[0];
    // Iterate through the vector, calculating the running sum
    for (int i = 1; i < size; i++)
        sums[i] = nums[i] + sums[i - 1];
    return sums;
}
