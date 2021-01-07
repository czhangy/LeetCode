#include errors.h

// 628. Maximum Product of Three Numbers - Easy - Array/Math
// -------------------------------------------------------------
// Given an integer array nums, find three numbers whose product is maximum and return the maximum product.
// -------------------------------------------------------------
// Solve #1 | 8/21/20 | Time: 10:14 | Avg. Runtime: 248.8ms

int maximumProduct(vector<int> &nums) { // O(N) time, O(1) space
    // Initialization
    int min_c = INT_MAX, min_n = INT_MAX;
    int max_c = INT_MIN, max_n = INT_MIN, max_n_n = INT_MIN;
    int size = nums.size();
    // Loop through array and assign values, trickle down as necessary
    for (int i = 0; i < size; i++) {
        // Get 2 smallest elements
        if (min_c > nums[i]) {
            min_n = min_c;
            min_c = nums[i];
        } else if (min_n > nums[i])
            min_n = nums[i];
        // Get 3 largest elements
        if (max_c < nums[i]) {
            max_n_n = max_n;
            max_n = max_c;
            max_c = nums[i];
        } else if (max_n < nums[i]) {
            max_n_n = max_n;
            max_n = nums[i];
        } else if (max_n_n < nums[i])
            max_n_n = nums[i];
    }
    // Account for potential negative usage
    return max(min_c * min_n * max_c, max_n_n * max_n * max_c);
}