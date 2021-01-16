#include "errors.h"
#include <vector>

using namespace std;

// 852. Peak Index In A Mountain Array - Easy - Binary Search
// -------------------------------------------------------------
// Let's call an array arr a mountain if the following properties hold:
// - arr.length >= 3
// - There exists some i with 0 < i < arr.length - 1 such that:
//    - arr[0] < arr[1] < ... arr[i-1] < arr[i]
//    - arr[i] > arr[i+1] > ... > arr[arr.length - 1]
// Given an integer array arr that is guaranteed to be a mountain, return any i such that arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].
// -------------------------------------------------------------
// Solve #1 | 09/19/20 | Time: 4:17 | Avg. Runtime: 21.6ms

int peakIndexInMountainArray(vector<int> &arr) { // O(log N) time, O(1) space
    // Initialize bounds
    int left = 0, right = arr.size() - 1;
    // Binary search
    while (left < right) {
        // Calculate mid index, protecting against overflow
        int mid = left + (right - left) / 2;
        // Subarray is increasing, move left bound right
        if (arr[mid + 1] > arr[mid])
            left = mid + 1;
        // Subarray is decreasing, move right bound left
        else
            right = mid;
    }
    return left;
}
