#include "errors.h"

// 342. Power Of Four - Easy - Bit Manipulation
// -------------------------------------------------------------
// Given an integer n, return true if it is a power of four. Otherwise, return false.
// An integer n is a power of four, if there exists an integer x such that n == 4^x.
// -------------------------------------------------------------
// Solve #3 | 08/05/20 | Time: 2:17 | Avg. Runtime: 3.2ms

bool isPowerOfFour(int num) { // O(1) time, O(1) space
    // Check bit pattern and divisibility by 3
    return num > 0 && !(num & num - 1) && !((num - 1) % 3);
}
