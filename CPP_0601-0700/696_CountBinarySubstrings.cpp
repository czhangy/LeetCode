#include "errors.h"
#include <string>

using namespace std;

// 696. Count Binary Substrings - Easy - String
// -------------------------------------------------------------
// Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.
// Substrings that occur multiple times are counted the number of times they occur.
// -------------------------------------------------------------
// Solve #1 | 09/03/20 | Time: 4:19 | Avg. Runtime: 68ms

int countBinarySubstrings(string s) { // O(N^2) time, O(N) space
    // Catch empty string edge case
    if (s.empty())
        return 0;
    // Initialize
    char curChar = s[0];
    int count = 1, i = 1, size = s.size();
    // Count matching sequence of MSBs
    while (i < size && s[i] == curChar) {
        count++;
        i++;
    }
    // Count opposing sequence
    int j = i;
    while (j < size && s[j] != curChar && count) {
        j++;
        count--;
    }
    // Remove MSB and LSB
    string str = s.substr(1, size - 1);
    // Recursively check the substring
    return !count ? countBinarySubstrings(str) + 1 : countBinarySubstrings(str);
}
