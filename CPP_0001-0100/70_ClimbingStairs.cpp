#include "errors.h"

// 70. Climbing Stairs - Easy - Dynamic Programming
// -------------------------------------------------------------
// You are climbing a staircase.
// It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps.
// In how many distinct ways can you climb to the top?
// -------------------------------------------------------------
// Solve #3 | 07/04/20 | Time: 2:43 | Avg. Runtime: 1.6ms

int climbStairs(int n) { // O(N) time, O(1) space
    // Account for less than or equal to 2 steps edge case
    if (n <= 2)
        return n;
    // Initialize
    int finalStair, stairOne = 1, stairTwo = 2;
    // Iterate while taking dynamic programming into account
    for (int i = 2; i < n; i++) {
        finalStair = stairOne + stairTwo;
        stairOne = stairTwo;
        stairTwo = finalStair;
    }
    return finalStair;
}
