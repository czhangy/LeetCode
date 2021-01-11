#include "errors.h"

// 1281. Subtract The Product And Sum Of Digits Of An Integer - Easy - Math
// -------------------------------------------------------------
// Given an integer number n, return the difference between the product of its digits and the sum of its digits.
// -------------------------------------------------------------
// Solve #1 | 09/23/20 | Time: 1:24 | Avg. Runtime: 0ms

int subtractProductAndSum(int n) { // O(N) time, O(1) space
    // Initialize
    int sum = 0, product = 1;
    // Break down n
    while (n) {
        // Get current digit
        int curDigit = n % 10;
        // Modify running totals
        sum += curDigit;   
        product *= curDigit;
        // Iterate forwards 
        n /= 10;
    }
    return product - sum;
}
