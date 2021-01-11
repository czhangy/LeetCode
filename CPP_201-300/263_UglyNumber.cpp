#include "errors.h"

// 263. Ugly Number - Easy - Math
// -------------------------------------------------------------
// Write a program to check whether a given number is an ugly number.
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
// -------------------------------------------------------------
// Solve #1 | 07/17/20 | Time: 4:00 | Avg. Runtime: 0.8ms

bool isUgly(int num) { // Undefined time complexity, O(1) space
    // Catch 0 edge case
    if (!num)
        return false;
    // Break num down into factors
    while (num != 1) {
        // Check 2
        if (!(num % 2))
            num /= 2;
        // Check 3
        else if (!(num % 3))
            num /= 3;
        // Check 5
        else if (!(num % 5))
            num /= 5;
        // Other factor found --> not ugly
        else
            return false;
    }
    return true;
}
