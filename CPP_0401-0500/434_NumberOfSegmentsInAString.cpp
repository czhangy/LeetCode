#include "errors.h"
#include <string>

using namespace std;

// 434. Number Of Segments In A String - Easy - String
// -------------------------------------------------------------
// You are given a string s, return the number of segments in the string.
// A segment is defined to be a contiguous sequence of non-space characters.
// -------------------------------------------------------------
// Solve #1 | 07/29/20 | Time: 7:59 | Avg. Runtime: 0.8ms

int countSegments(string s) { // O(N) time, O(1) space
    // Initialize
    int size = s.size(), numSegs = 0;
    // Iterate through the string
    for (int i = 0; i < size; i++) {
        // Account for spaces at the end of the string
        if (!isspace(s[i])) {
            numSegs++;
            // Move i to next segment
            while (i < size && !isspace(s[i]))
                i++;
        }
    }
    return numSegs;
}
