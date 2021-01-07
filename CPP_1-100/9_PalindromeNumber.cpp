#include "errors.h"

// 9. Palindrome Number - Easy - Math
// -------------------------------------------------------------
// Determine whether an integer is a palindrome.
// An integer is a palindrome when it reads the same backward as forward.
// -------------------------------------------------------------
// Solve #1 | 06/26/20 | Time: 2:17 | Avg. Runtime: 16ms

bool isPalindrome(int x) { // O(N) time, O(1) space
    // Account for edge cases
    if (x < 0 || (x && !(x % 10)))
        return false;
    // Initialize
    int sum = 0;
    // Build variables
    while (x > sum) {
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    // Return palindrome
    return (x == sum) || (x == sum / 10);
}
