#include "errors.h"
#include <vector>

using namespace std;

// 88. Merge Sorted Array - Easy - Array/Two Pointers
// -------------------------------------------------------------
// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
// The number of elements initialized in nums1 and nums2 are m and n respectively.
// You may assume that nums1 has a size equal to m + n such that it has enough space to hold additional elements from nums2.
// -------------------------------------------------------------
// Solve #2 | 02/16/21 | Time: 15:20 | Avg. Runtime: 0.8ms

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) { // O(M + N) time, O(1) space
    // Catch empty vector edge cases
    if (!m) {
        nums1 = nums2;
        return;
    } else if (!n)
        return;
    // Initialize
    int i1 = m - 1, i2 = n - 1;
    // Iterate backwards through vector
    for (int i = m + n - 1; i >= 0; i--) {
        // If nums1 ran out
        if (i1 < 0) {
            nums1[i] = nums2[i2];
            i2--;
        // If nums2 ran out
        } else if (i2 < 0) {
            nums1[i] = nums1[i1];
            i1--;
        } else {
            // Merge using the greatest value available
            nums1[i] = max(nums1[i1], nums2[i2]);
            if (nums1[i1] > nums2[i2])
                i1--;
            else
                i2--;
        }
    }
}
