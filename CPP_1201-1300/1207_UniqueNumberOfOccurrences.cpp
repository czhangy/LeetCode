#include "errors.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// 1207. Unique Number Of Occurrences - Easy - Hash Table
// -------------------------------------------------------------
// Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array is unique.
// -------------------------------------------------------------
// Solve #1 | 02/13/21 | Time: 2:07 | Avg. Runtime: 3.2ms

bool uniqueOccurrences(vector<int> &arr) { // O(N) time, O(N) space
    // Initialize
    unordered_map<int, int> count;
    unordered_set<int> dupes;
    // Map all numbers to their number of occurrences
    for (int x : arr)
        count[x]++;
    // Check for duplicate occurrences
    for (auto &iter : count) {
        // Duplicate found
        if (dupes.count(iter.second))
            return false;
        // Insert number of occurrences into hash set
        dupes.insert(iter.second);
    }
    return true;
}
