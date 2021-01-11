#include "errors.h"
#include <string>
#include <vector>

using namespace std;

// 228. SummaryRanges - Easy - Array
// -------------------------------------------------------------
// You are given a sorted unique integer array nums.
// Return the smallest sorted list of ranges that cover all the numbers in the array exactly.
// That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
// Each range [a,b] in the list should be output as:
// - "a->b" if a != b
// - "a" if a == b
// -------------------------------------------------------------
// Solve #1 | 12/23/20 | Time: 5:14 | Avg. Runtime: 0ms

vector<string> summaryRanges(vector<int> &nums) { // O(N) time, O(N) space
    // Initialize
    vector<string> res;
    int size = nums.size();
    // Iterate through the vector
    for (int i = 0; i < size; i++) {
        int start = nums[i], last = start;
        // Get next consecutive interval
        while (i + 1 < size && nums[i + 1] == nums[i] + 1) {
            last = nums[i + 1];
            i++;
        }
        // No interval, push a single value into res
        if (start == last)
            res.push_back(to_string(start));
        // Push interval into res
        else
            res.push_back(to_string(start) + "->" + to_string(last));
    }
    return res;
}
