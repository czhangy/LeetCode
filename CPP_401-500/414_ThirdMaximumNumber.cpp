#include "errors.h"
#include <set>
#include <vector>

using namespace std;

// 414. Third Maximum Number - Easy - Array
// -------------------------------------------------------------
// Given integer array nums, return the third maximum number in this array.
// If the third maximum does not exist, return the maximum number.
// -------------------------------------------------------------
// Solve #2 | 08/05/20 | Time: 17:39 | Avg. Runtime: 25.2ms

int thirdMax(vector<int> &nums) { // O(N) time, O(1) space
    // Initialize --> set to track order implicitly
    set<int> maxes;
    // Iterate through nums
    for (int num : nums) {
        // Insert if the set hasn't reached capacity
        if (maxes.size() < 3)
            maxes.insert(num);
        // If value represents a new top 3 value, replace the old 3rd highest
        else if (num > *maxes.begin() && !maxes.count(num)) {
            maxes.erase(maxes.begin());
            maxes.insert(num);
        }
    }
    // Return based on the spec
    return maxes.size() == 3 ? *maxes.begin() : *maxes.rbegin();
}
