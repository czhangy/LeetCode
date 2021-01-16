#include "errors.h"
#include <string>
#include <vector>

using namespace std;

// 942. DI String Match - Easy - Math
// -------------------------------------------------------------
// Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.
// Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:
// - If S[i] == "I", then A[i] < A[i+1]
// - If S[i] == "D", then A[i] > A[i+1]
// -------------------------------------------------------------
// Solve #1 | 12/23/20 | Time: 5:41 | Avg. Runtime: 6.4ms

vector<int> diStringMatch(string S) { // O(N) time, O(N) space
    // Initialize
    int size = S.size(), max = size, min = 0;
    vector<int> res(size + 1);
    bool inc = true;
    for (int i = 0; i < size; i++) {
        // Increase needed, set index the minimum available value
        if (S[i] == 'I') {
            res[i] = min;
            min++;
            inc = true;
        // Decrease needed, set index the maximum available value
        } else {
            res[i] = max;
            max--;
            inc = false;
        }
    }
    // Set the last index to the remaining value
    res[size] = max;
    return res;
}
