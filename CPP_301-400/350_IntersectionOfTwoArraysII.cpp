#include "errors.h"
#include <unordered_map>
#include <vector>

using namespace std;

// 350. Intersection Of Two Arrays II - Easy - Hash Table/Two Pointers/Binary Search/Sort
// -------------------------------------------------------------
// Given two arrays, write a function to compute their intersection.
// -------------------------------------------------------------
// Solve #1 | 07/22/20 | Time: 2:42 | Avg. Runtime: 16ms

vector<int> intersect(vector<int> &nums1, vector<int> &nums2) { // O(N + M) time, O(N + M) space
    // Initialize
    vector<int> res;
    int size1 = nums1.size(), size2 = nums2.size();
    unordered_map<int, int> hash;
    // Map all array values to their number of occurrences in nums1
    for (int x : nums1)
        hash[x]++;
    // Iterate through nums2
    for (int x : nums2)
        // If the value was in nums1, insert it into the result and decrement the number of occurrences
        if (hash[x]) {
            res.push_back(x);
            hash[x]--;
        }
    return res;
}
