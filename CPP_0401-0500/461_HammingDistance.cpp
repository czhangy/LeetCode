#include "errors.h"

// 461. Hamming Distance - Easy - Bit Manipulation
// -------------------------------------------------------------
// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
// Given two integers x and y, calculate the Hamming distance.
// -------------------------------------------------------------
// Solve #1 | 08/01/20 | Time: 2:52 | Avg. Runtime: 0ms

int hammingDistance(int x, int y) { // O(1) time, O(1) space
    // Problem statement is the definition of exclusive-or
    x ^= y;
    // Initialize
    int count = 0;
    // Iterate through result of xor, incrementing count as needed
    while (x) {
        if (x & 1)
            count++;
        x >>= 1;
    }
    return count;
}
