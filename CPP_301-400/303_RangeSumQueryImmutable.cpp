#include "errors.h"

// 303. Range Sum Query-Immutable - Easy - Dynamic Programming
// -------------------------------------------------------------
// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
// Implement the NumArray class:
// - NumArray(int[] nums) Initializes the object with the integer array nums.
// - int sumRange(int i, int j) Return the sum of the elements of the nums array in the range [i, j] inclusive (i.e., sum(nums[i], nums[i + 1], ... , nums[j]))
// -------------------------------------------------------------
// Solve #1 | 7/20/20 | Time: 9:09 | Avg. Runtime: 37.6ms

class NumArray {
public:
    // Constructor
    NumArray(vector<int> &nums) {
        // Initialize
        int m_size = nums.size(), sum = 0;
        // Fill DP array
        for (int i = 0; i < m_size; i++) {
            sum += nums[i];
            m_sumArray.push_back(sum);
        }
    }

    // Get sum from i to j
    int sumRange(int i, int j) { // O(1) time, O(1) space
        // Handle edge case of i = 0 --> sum is just sum at j
        if (!i)
            return m_sumArray[j];
        // Handle average case --> use DP array to find difference
        else
            return m_sumArray[j] - m_sumArray[i - 1];
    }

private:
    vector<int> m_sumArray; // DP array
};