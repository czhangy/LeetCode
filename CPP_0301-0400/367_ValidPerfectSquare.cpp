#include "errors.h"

// 367. Valid Perfect Square - Easy - Math/Binary Search
// -------------------------------------------------------------
// Given a positive integer num, write a function which returns true if num is a perfect square, and false otherwise.
// Do not use any built-in library functions such as sqrt.
// -------------------------------------------------------------
// Solve #1 | 07/23/20 | Time: 8:19 | Avg. Runtime: 0.8ms

bool isPerfectSquare(int num) { // O(log N) time, O(1) space
    // Catch 1 edge case
    if (num == 1)
        return true;
    // Initialize bounds
    int left = 0, right = num / 2;
    // Binary search
    while (left < right) {
        // Calculate mid index, protecting against overflow
        int mid = left + (right - left) / 2;
        // Middle value squared is less than target --> move left bound right
        if (num / mid > mid)
            left = mid + 1;
        // Middle value squared is more than target --> move right bound left
        else
            right = mid;
    }
    // Hard-code overflow protection, check if valid square
    return left < 46341 && left * left == num;
}
