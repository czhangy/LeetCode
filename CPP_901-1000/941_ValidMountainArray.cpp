#include "errors.h"
#include <vector>

using namespace std;

// 941. Valid Mountain Array - Easy - Array
// -------------------------------------------------------------
// Given an array of integers arr, return true if and only if it is a valid mountain array.
// Recall that arr is a mountain array if and only if:
// - arr.length >= 3
// - There exists some i with 0 < i < arr.length - 1 such that:
//   - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//   - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// -------------------------------------------------------------
// Solve #1 | 10/04/20 | Time: 8:05 | Avg. Runtime: 53.6ms

bool validMountainArray(vector<int> &A) { // O(N) time, O(1) space
    // Initialize
    int size = A.size();
    bool inc = true;
    // Catch the non-increasing and small size edge cases
    if (size < 3 || A[0] > A[1])
        return false;
    // Iterate through the vector
    for (int i = 0; i < size - 1; i++) {
        // If adjacent elements are equal, or an increase happens in the decreasing subarray --> failure condition
        if (A[i] == A[i + 1] || (!inc && A[i] < A[i + 1]))
            return false;
        // Set flag for decreasing subarray
        else if (A[i] > A[i + 1])
            inc = false;
    }
    // Check if the vector has both increasing and decreasing subarrays
    return !inc;
}
