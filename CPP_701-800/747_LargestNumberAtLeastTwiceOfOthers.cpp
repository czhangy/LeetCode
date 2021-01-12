#include "errors.h"
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

// 747. Largest Number At Least Twice Of Others - Easy - Array
// -------------------------------------------------------------
// In a given integer array nums, there is always exactly one largest element.
// Find whether the largest element in the array is at least twice as much as every other number in the array.
// If it is, return the index of the largest element, otherwise return -1.
// -------------------------------------------------------------
// Solve #1 | 09/10/20 | Time: 5:51 | Avg. Runtime: 6.4ms

int dominantIndex(vector<int> &nums) { // O(N log N) time, O(N) time
    // Initialize
    int size = nums.size();
    unordered_map<int, int> m;
    // Catch 1 length edge case
    if (nums.size() == 1)
        return 0;
    // Map all values to their index, can ignore repeated values because the largest is guaranteed to be unique
    for (int i = 0; i < size; i++)
        m[nums[i]] = i;
    // Sort
    sort(nums.begin(), nums.end());
    // Check if the largest element is at least twice as large as second largest
    return nums[size - 1] >= (nums[size - 2]) << 1 ? m[nums[size - 1]] : -1;
}
