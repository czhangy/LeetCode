#include "errors.h"
#include <algorithm>
#include <vector>

using namespace std;

// 56. Merge Intervals - Medium - Array/Sort
// -------------------------------------------------------------
// Given an array of intervals where intervals[i] = [start_i, end_i], merge all overlapping intervals, and return an array
// of the non-overlapping intervals that cover all the intervals in the input.
// -------------------------------------------------------------
// Solve #1 | 12/27/20 | Time: 14:38 | Avg. Runtime: 32.8ms

vector<vector<int>> merge(vector<vector<int>> &intervals) { // O(N log N) time, O(N) space
    // Sort intervals based on start time
    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
    // Initialize
    vector<vector<int>> res;
    int size = intervals.size(), i = 0;
    // Iterate through intervals
    while (i < size) {
        // Initialize
        int start = intervals[i][0], end = intervals[i][1];
        i++;
        // Merge overlapping intervals
        while (i < size && intervals[i][0] <= end) {
            end = max(end, intervals[i][1]);
            i++;
        }
        // Push new interval into result vector
        res.push_back({start, end});
    }
    return res;
}
