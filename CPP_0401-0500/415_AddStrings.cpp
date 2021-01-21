#include "errors.h"
#include <string>

using namespace std;

// 415. Add Strings - Easy - String
// -------------------------------------------------------------
// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
// -------------------------------------------------------------
// Solve #2 | 08/05/20 | Time: 5:15 | Avg. Runtime: 7.2ms

string addStrings(string num1, string num2) { // O(N + M) time, O(max(N, M)) space
    // Initialize
    string res;
    // Iterate through strings in reverse order
    for (int i = num1.size() - 1, j = num2.size() - 1, carry = 0; i >= 0 || j >= 0 || carry;) {
        // If num1 still needs to be processed, account for carry
        if (i >= 0) {
            carry += num1[i] - '0';
            i--;
        }
        // If num2 still needs to be processed, account for carry
        if (j >= 0) {
            carry += num2[j] - '0';
            j--;
        }
        // Apply carry
        res += '0' + carry % 10;
        carry /= 10;
    }
    // Account for building string in reverse order
    reverse(res.begin(), res.end());
    return res;
}
