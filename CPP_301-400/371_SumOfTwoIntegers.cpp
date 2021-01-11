#include "errors.h"

// 371. Sum Of Two Integers - Medium - Bit Manipulation
// -------------------------------------------------------------
// Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
// -------------------------------------------------------------
// Solve #3 | 08/05/20 | Time: 5:54 | Avg. Runtime: 1.6ms

int getSum(int a, int b) { // Undefined time complexity, undefined space complexity
    return helperFunc(a, b);
}

// Recursive function --> allows for unsigned interpretation
int helperFunc(unsigned int a, unsigned int b) {
    // Bit manipulation to mimic addition
    return !b ? a : helperFunc(a ^ b, (a & b) << 1);
}
