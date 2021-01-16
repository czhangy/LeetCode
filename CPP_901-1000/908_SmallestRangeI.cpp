#include "errors.h"
#include <vector>

using namespace std;

// 908. Smallest Range I - Easy - Math
// -------------------------------------------------------------
// Given an array A of integers, for each integer A[i] we may choose any x with -K <= x <= K, and add x to A[i].
// After this process, we have some array B.
// Return the smallest possible difference between the maximum value of B and the minimum value of B.
// -------------------------------------------------------------
// Solve #1 | 09/18/20 | Time: 5:38 | Avg. Runtime: 35.2ms

int smallestRangeI(vector<int> &A, int K) { // O(N) time, O(1) space
    // Initialize
    int minVal = A[0], maxVal = A[0];
    // Iterate through the vector
    for (int x : A) {
        // Track minimums and maximums
        minVal = min(minVal, x);
        maxVal = max(maxVal, x);
    }
    // Get difference between values if K is applied
    int diff = maxVal - minVal - (K << 1);
    // Check if the difference was completely closed
    return max(diff, 0);
}
