#include "errors.h"
#include <string>
#include <vector>

using namespace std;

// 830. Positions Of Large Groups - Easy - Array
// -------------------------------------------------------------
// In a string s of lowercase letters, these letters form consecutive groups of the same character.
// For example, a string like s = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z", and "yy".
// A group is identified by an interval [start, end], where start and end denote the start and end indices (inclusive) of the group.
// In the above example, "xxxx" has the interval [3,6].
// A group is considered large if it has 3 or more characters.
// Return the intervals of every large group sorted in increasing order by start index.
// -------------------------------------------------------------
// Solve #1 | 09/14/20 | Time: 5:36 | Avg. Runtime: 6.4ms

vector<vector<int>> largeGroupPositions(string s) { // O(N) time, O(N) space
    // Initialize
    vector<vector<int>> res;
    int size = s.size(), startIndex = 0;
    char prev = s[0];
    // Iterate through string
    for (int i = 1; i < size; i++) {
        // If group broken
        if (prev != s[i]) {
            // Update result if necessary
            if (i - 1 - startIndex >= 2)
                res.push_back({startIndex, i - 1});
            // Begin searching for next group
            startIndex = i;
            prev = s[i];
        }
    }
    // Check for last sequence
    if (size - 1 - startIndex >= 2)
        res.push_back({startIndex, size - 1});
    return res;
}
