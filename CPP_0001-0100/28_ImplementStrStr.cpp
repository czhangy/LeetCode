#include "errors.h"
#include <string>

using namespace std;

// 28. Implement strStr() - Easy - Two Pointers/String
// -------------------------------------------------------------
// Implement strStr().
// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
// -------------------------------------------------------------
// Solve #1 | 06/27/20 | Time: 5:31 | Avg. Runtime: 73.6ms

int strStr(string haystack, string needle) { // O(N^2) time, O(1) space
    // Initialize
    int len = haystack.size();
    // Catch empty string edge case
    if (!needle.size())
        return 0;
    // Iterate through string
    for (int i = 0; i < len; i++)
        // Check substring for needle
        if (haystack[i] == needle[0] && haystack.substr(i, needle.size()) == needle)
            return i;
    // Needle not found, return appropriately
    return -1;
}
