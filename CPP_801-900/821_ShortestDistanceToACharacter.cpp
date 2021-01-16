#include "errors.h"
#include <string>
#include <vector>

using namespace std;

// 821. Shortest Distance To A Character - Easy - String
// -------------------------------------------------------------
// Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.
// -------------------------------------------------------------
// Solve #1 | 09/14/20 | Time: 14:14 | Avg. Runtime: 3.2ms

vector<int> shortestToChar(string S, char C) { // O(N) time, O(N) space
    // Initialize
    int size = S.size(), curIndex = 0;
    vector<int> dists(size), indexes;
    // Locate all occurrences of C
    for (int i = 0; i < size; i++)
        if (S[i] == C)
            indexes.push_back(i);
    // Iterate through the string
    for (int i = 0; i < size; i++) {
        // Catch current character is C edge case
        if (curIndex < indexes.size() && indexes[curIndex] == i) {
            curIndex++;
            dists[i] = 0;
            continue;
        }
        // If a left and right target index exist
        if (curIndex && curIndex < indexes.size())
            // Pick the shortest direction
            dists[i] = min(abs(indexes[curIndex] - i), abs(indexes[curIndex - 1] - i));
        // If only a right target index exists, use it
        else if (!curIndex)
            dists[i] = indexes[0] - i;
        // If only a left target index exists, use it
        else
            dists[i] = i - indexes[indexes.size() - 1];
    }
    return dists;
}
