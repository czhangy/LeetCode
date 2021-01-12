#include "errors.h"
#include <algorithm>

using namespace std;

// 633. Sum Of Square Numbers - Medium - Math
// -------------------------------------------------------------
// Given a non-negative integer c, decide whether there're two integers a and b such that a^2 + b^2 = c.
// -------------------------------------------------------------
// Solve #1 | 08/22/20 | Time: 6:48 | Avg. Runtime: 6.4ms

bool judgeSquareSum(int c) { // O(sqrt(N)) time, O(1) space
    // Iterate through all possible values
    for (int upper = sqrt(c); upper >= 0; upper--) {
        // Initialize
        int val = upper * upper, temp = sqrt(c - val);
        // Check if cutoff happened
        if (temp * temp + val == c)
            return true;
    }
    return false;
}
