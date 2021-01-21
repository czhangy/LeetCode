#include "errors.h"
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

// 1122. Relative Sort Array - Easy - Array/Sort
// -------------------------------------------------------------
// Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
// Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.
// Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.
// -------------------------------------------------------------
// Solve #1 | 01/21/21 | Time: 5:28 | Avg. Runtime: 3.2ms

vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) { // O(N log N) time, O(N) space
    // Initialize
    unordered_map<int, int> nums;
    vector<int> res;
    int index;
    // Map all values in arr1 to their number of occurrences
    for (int x : arr1)
        nums[x]++;
    // Iterate through arr2
    for (int x : arr2)
        // Insert number of occurrences of a number in arr1 into result
        while (nums[x]) {
            res.push_back(x);
            nums[x]--;
        }
    // Save the index where non-arr2 elements begin
    index = res.size();
    // Push all remaining elements from arr1 into result
    for (auto &iter : nums)
        while (iter.second) {
            res.push_back(iter.first);
            iter.second--;
        }
    // Sort the non-arr2 subarray
    sort(res.begin() + index, res.end());
    return res;
}
