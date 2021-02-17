#include "errors.h"
#include <string>

using namespace std;

// 1221. Split A String In Balanced Strings - Easy - String/Greedy
// -------------------------------------------------------------
// Balanced strings are those that have an equal quantity of 'L' and 'R' characters.
// Given a balanced string s, split it in the maximum amount of balanced strings.
// Return the maximum amount of split balanced strings.
// -------------------------------------------------------------
// Solve #1 | 02/16/21 | Time: 1:46 | Avg. Runtime: 0.8ms

int balancedStringSplit(string s) { // O(N) time, O(1) space
    // Initialize
    int L = 0, R = 0, count = 0;
    // Iterate through the string
    for (char c : s) {
        // Count current Ls
        if (c == 'L')
            L++;
        // Count current Rs
        else if (c == 'R')
            R++;
        // Matching number of Ls and Rs, reset counts and increment
        if (L == R) {
            L = 0;
            R = 0;
            count++;
        }
    }
    return count;
}
