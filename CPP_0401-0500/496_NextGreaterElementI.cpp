#include "errors.h"
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

// 496. Next Greater Element I - Easy - Stack
// -------------------------------------------------------------
// You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2.
// Find all the next greater numbers for nums1's elements in the corresponding places of nums2.
// The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2.
// If it does not exist, output -1 for this number.
// -------------------------------------------------------------
// Solve #1 | 08/04/20 | Time: 5:33 | Avg. Runtime: 11.2ms

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) { // O(N + M) time, O(N) space
    // Initialize
    unordered_map<int, int> firstApp;
    int size1 = nums1.size(), size2 = nums2.size();
    vector<int> res(size1);
    // Iterate through the set, mapping values to the index of their earliest occurrence
    for (int i = 0; i < size2; i++) {
        if (!firstApp[nums2[i]])
            firstApp[nums2[i]] = i;
    }
    // Iterate through the subset
    for (int i = 0; i < size1; i++) {
        // Initialize
        int temp = nums1[i], j = firstApp[temp] + 1;
        // Match subset value to corresponding value in set
        while (j < size2) {
            // Next greater value found
            if (nums2[j] > temp) {
                res[i] = nums2[j];
                break;
            }
            j++;
        }
        // If no value found, use -1
        if (j == size2)
            res[i] = -1;
    }
    return res;
}
