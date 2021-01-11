#include "errors.h"

// 278. First Bad Version - Easy - Binary Search
// -------------------------------------------------------------
// You are a product manager and currently leading a team to develop a new product.
// Unfortunately, the latest version of your product fails the quality check.
// Since each version is developed based on the previous version, all the versions after a bad version are also bad.
// Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
// You are given an API bool isBadVersion(version) which returns whether version is bad.
// Implement a function to find the first bad version.
// You should minimize the number of calls to the API.
// -------------------------------------------------------------
// Solve #1 | 07/17/20 | Time: 3:38 | Avg. Runtime: 0.8ms

// Prototype
bool isBadVersion(int val);

int firstBadVersion(int n) { // O(log N) time, O(1) space
    // Initialize search bounds
    int left = 1, right = n;
    // Binary search
    while (left < right) {
        // Calculate mid index, accounting for potential overflow
        int mid = (left >> 1) + (right >> 1);
        // Middle version isn't bad --> move left bound right
        if (!isBadVersion(mid))
            left = mid + 1;
         // Middle version is bad --> move right bound left
        else
            right = mid;
    }
    return left;
}
