#include "errors.h"
#include <vector>

using namespace std;

// 724. Find Pivot Index - Easy - Array
// -------------------------------------------------------------
// Given an array of integers nums, write a method that returns the "pivot" index of this array.
// We define the pivot index as the index where the sum of all the numbers to the left of the index is equal to the sum of all the numbers to the right of the index.
// If no such index exists, we should return -1.
// If there are multiple pivot indexes, you should return the left-most pivot index.
// -------------------------------------------------------------
// Solve #1 | 09/08/20 | Time: 9:54 | Avg. Runtime: 47.2ms

int pivotIndex(vector<int> &nums) { // O(N) time, O(N) space
    // Initialize
    int size = nums.size();
    vector<int> left(size), right(size);
    // Iteratively populate each DP array
    for (int i = 1, j = size - 2; i < size; i++, j--) { 
        left[i] = nums[i - 1] + left[i - 1];
        right[j] = nums[j + 1] + right[j + 1];
    }
    // Find an index where left sum is equal to right sum
    for (int i = 0; i < size; i++)
        if (left[i] == right[i])
            return i;
    // No pivot found
    return -1;
}
