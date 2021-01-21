#include "errors.h"
#include <string>

using namespace std;

// 171. Excel Sheet Column Number - Easy - Math
// -------------------------------------------------------------
// Given a column title as appear in an Excel sheet, return its corresponding column number.
// -------------------------------------------------------------
// Solve #1 | 07/07/20 | Time: 3:41 | Avg. Runtime: 4ms

int titleToNumber(string s) { // O(N) time, O(N) space
    // Initialization
    int size = s.size(), magnitude = size - 1, val = 0;
    // Convert to base 10
    for (int i = 0; i < size; i++, magnitude--) {
        int base = s[i] - 'A' + 1;
        val += base * pow(26, magnitude);
    }
    return val;
}
