#include "errors.h"
#include <cstdint>

using namespace std;

// 191. Number Of 1 Bits - Easy - Bit Manipulation
// -------------------------------------------------------------
// Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
// -------------------------------------------------------------
// Solve #1 | 07/09/20 | Time: 1:16 | Avg. Runtime: 5.6ms

int hammingWeight(uint32_t n) { // O(1) time, O(1) space
    // Initialization
    int count = 0;
    // Count bits
    while (n) {
        if (n & 1)
            count++;
        n >>= 1;
    }
    return count;
}
