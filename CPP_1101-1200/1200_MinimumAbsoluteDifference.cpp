#include "errors.h"
#include <algorithm>
#include <vector>

using namespace std;

// 1200. Minimum Absolute Difference - Easy - Array
// -------------------------------------------------------------
// Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.
// Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
// - a, b are from arr
// - a < b
// - b - a equals to the minimum absolute difference of any two elements in arr
// -------------------------------------------------------------
// Solve #1 | 02/12/21 | Time: 4:34 | Avg. Runtime: 65.6ms

vector<vector<int>> minimumAbsDifference(vector<int> &arr) { // O(N log N) time, O(N) space
    // Initialize
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    int minDiff = INT_MAX, size = arr.size();
    // Iterate through array
    for (int i = 0; i + 1 < size; i++) {
        // Get current values of a and b
        int a = min(arr[i + 1], arr[i]), b = max(arr[i + 1], arr[i]), diff = b - a;
        // If a new minimum difference is found
        if (diff < minDiff) {
            minDiff = diff;
            res.clear();
            res.push_back({a, b});
        }
        // If an equal minimum difference is found
        else if (diff == minDiff)
            res.push_back({a, b});
    }
    return res;
}
