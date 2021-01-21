#include "errors.h"

// 476. Number Complement - Easy - Bit Manipulation
// -------------------------------------------------------------
// Given a positive integer num, output its complement number.
// The complement strategy is to flip the bits of its binary representation.
// -------------------------------------------------------------
// Solve #1 | 08/02/20 | Time: 7:15 | Avg. Runtime: 0ms

int findComplement(int num) {
    // Initialize
    int comp = ~num, mag = 0, temp = 0;
    // Find MSB
    while (num) {
        if (num & 1)
            mag = temp;
        temp++;
        num >>= 1;
    }
    // Calculate magnitude of MSB
    temp = pow(2, mag + 1) - 1;
    // Mask for result
    return comp & temp;
}
