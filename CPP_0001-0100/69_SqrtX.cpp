#include "errors.h"

// 69. Sqrt(x) - Easy - Math/Binary Search
// -------------------------------------------------------------
// Given a non-negative integer x, compute and return the square root of x.
// Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.
// -------------------------------------------------------------
// Solve #2 | 02/16/21 | Time: 10:46 | Avg. Runtime: 1.6ms

int mySqrt(int x) { // O(log N) time, O(1) space
    // Catch x = sqrt(x) edge cases
    if (x < 2)
        return x;
    // Initialize
    int left = 1, right = x / 2;
    // Binary search
    while (left <= right) {
        // Calculate mid index, protecting against overflow
        int mid = (left + right) / 2, midVal = x / mid;
        // Complement value too high --> move left bound right
        if (mid < midVal)
            left = mid + 1;
        // Complement value too low --> move right bound left
        else if (mid > midVal)
            right = mid - 1;
        // Complement value equals value --> square root found
        else
            return mid;
    }
    return left - 1;
}
