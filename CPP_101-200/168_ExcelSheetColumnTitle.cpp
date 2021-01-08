#include "errors.h"
#include <string>

using namespace std;

// 168. Excel Sheet Column Title - Easy - Math
// -------------------------------------------------------------
// Given a positive integer, return its corresponding column title as appear in an Excel sheet.
// -------------------------------------------------------------
// Solve #2 | 07/09/20 | Time: 1:28 | Avg. Runtime: 1.6ms

string convertToTitle(int n) { // O(N) time, O(N) space
    // Initialize
    string str;
    // Convert to base 26
    while (n) {
        n--;
        char curChar = (n % 26) + 'A';
        // Build string in reverse order
        str = curChar + str;
        n /= 26;
    }
    return str;
}
