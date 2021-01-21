#include "errors.h"
#include <vector>

using namespace std;

// 66. Plus One - Easy - Array
// -------------------------------------------------------------
// Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.
// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
// You may assume the integer does not contain any leading zero, except the number 0 itself.
// -------------------------------------------------------------
// Solve #1 | 06/29/20 | Time: 13:55 | Avg. Runtime: 4ms

vector<int> plusOne(vector<int> &digits) { // O(N) time, O(1) space
    // Initialize
    int size = digits.size();
    // Common case
    if (digits[size - 1] != 9) {
        digits[size - 1]++;
        return digits;
    // Catch carry edge case
    } else {
        // Initialize
        int count = 1;
        // While carry needs to be addressed
        while (size - count && digits[size - count] == 9)
        {
            // Implement carry on current digit
            digits[size - count] = 0;
            // If carried to first digit of integer
            if (!(size - count)) {
                // Add new first digit, push last 0 digit to back of integer
                digits[0] = 1;
                digits.push_back(0);
                return digits;
            }
            // Move to next digit
            count++;
        }
        // Apply carry
        digits[size - count]++;
        return digits;
    }
}
