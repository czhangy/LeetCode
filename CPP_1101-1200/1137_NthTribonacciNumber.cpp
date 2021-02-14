#include "errors.h"

// 1137. Nth Tribonacci Number - Easy - Recursion
// -------------------------------------------------------------
// The Tribonacci sequence Tn is defined as follows:
// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
// Given n, return the value of Tn.
// -------------------------------------------------------------
// Solve #1 | 02/12/21 | Time: 3:00 | Avg. Runtime: 0ms

int tribonacci(int n) { // O(N) time, O(1) space
    // Initialize
    int first = 0, second = 1, third = 1;
    // Handle edge cases
    if (!n)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    // Calculate next term
    for (int i = 3; i < n; i++) {
        int temp = first + second + third;
        first = second;
        second = third;
        third = temp;
    }
    return first + second + third;
}
