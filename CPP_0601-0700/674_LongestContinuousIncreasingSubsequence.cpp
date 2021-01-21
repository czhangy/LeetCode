#include "errors.h"
#include <vector>

using namespace std;

// 674. Longest Continuous Increasing Subsequence - Easy - Array
// -------------------------------------------------------------
// Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence (i.e. subarray).
// The subsequence must be strictly increasing.
// A continuous increasing subsequence is defined by two indices l and r (l < r) such that it is
//  [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].
// -------------------------------------------------------------
// Solve #1 | 08/27/20 | Time: 3:31 | Avg. Runtime: 18.4ms

int findLengthOfLCIS(vector<int> &nums) { // O(N) time, O(1) space
    // Handle empty vector edge case
    if (nums.empty())
        return 0;
    // Initialize
    int maxLen = 1, curLen = 1, size = nums.size();
    // Iterate through vector
    for (int i = 1; i < size; i++) {
        // If current subsequence is increasing
        if (nums[i] > nums[i - 1])
            curLen++;
        // Set best so far if subsequence broke
        else {
            maxLen = max(curLen, maxLen);
            curLen = 1;
        }
    }
    // Account for checking of current subsequence
    return max(curLen, maxLen);
}
