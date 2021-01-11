#include "errors.h"

// 231. Power Of Two - Easy - Math/Bit Manipulation
// -------------------------------------------------------------
// Given an integer n, return true if it is a power of two. Otherwise, return false.
// An integer n is a power of two, if there exists an integer x such that n == 2^x.
// -------------------------------------------------------------
// Solve #1 | 07/14/20 | Time: 2:24 | Avg. Runtime: 1.6ms

bool isPowerOfTwo(int n) { // O(1) time, O(1) space
    // Initialize --> use long to avoid INT_MAX > n > 2^30 case
    long temp = 1;
    // Check all powers of 2 that are less than n
    while (temp <= n) {
        // Power of 2 found
        if (temp == n)
            return true;
        // Iterate forward
        temp <<= 1;
    }
    return false;
}
