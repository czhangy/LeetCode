#include "errors.h"
#include <string>

using namespace std;

// 67. Add Binary - Easy - Math/String
// -------------------------------------------------------------
// Given two binary strings a and b, return their sum as a binary string.
// -------------------------------------------------------------
// Solve #2 | 06/30/20 | Time: 12:37 | Avg. Runtime: 9.6ms

string addBinary(string a, string b) { // O(N + M) time, O(N + M) space
    // Initialize
    int carry = 0;
    string sum;
    // Iterate through both bit strings
    for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0 || carry; i--, j--, carry >>= 1) {
        // Adjust carry if i has bits left
        if (i >= 0)
            carry += a[i] == '1' ? 1 : 0;
        // Adjust carry if j has bits left
        if (j >= 0)
            carry += b[j] == '1' ? 1 : 0;
        // Append new MSB to end
        sum += (!(carry & 1) ? "0" : "1");
    }
    // Account for reverse building of bit string
    reverse(sum.begin(), sum.end());
    return sum;
}
