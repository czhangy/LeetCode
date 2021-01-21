#include "errors.h"

// 50. Pow(x, n) - Medium - Math/Binary Search
// -------------------------------------------------------------
// Implement pow(x, n), which calculates x raised to the power n (i.e. xn).
// -------------------------------------------------------------
// Solve #3 | 01/20/21 | Time: N/A | Avg. Runtime: 0ms

double myPow(double x, int n) { // O(1) time, O(1) space
    // Initialize
    double res = 1.0;
    // Leverage exponent multiplication to split the exponent in half
    for (int i = n; i; i /= 2, x *= x) {
        // If a 1 bit is found, apply the value to the result
        if (i & 1)
            res *= x;
    }
    // Account for negative exponents
    return n >= 0 ? res : 1 / res;
}
