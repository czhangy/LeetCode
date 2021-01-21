#include "errors.h"
#include <vector>

using namespace std;

// 704. Binary Search - Easy - Binary Search
// -------------------------------------------------------------
// Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums.
// If target exists, then return its index, otherwise return -1.
// -------------------------------------------------------------
// Solve #1 | 09/04/20 | Time: 7:03 | Avg. Runtime: 88ms

int search(vector<int> &nums, int target) { // O(log N) time, O(1) space
    // Initialize bounds
    int begin = 0, end = nums.size() - 1;
    // Binary search
    while (begin < end) {
        // Calclulate mid index, protecting against overflow
        int mid = begin + ((end - begin) >> 1);
        // If target value is greater than mid value, push left bound right
        if (nums[mid] < target)
            begin = mid + 1;
        // If target value is less than mid value, push right bound left
        else
            end = mid;
    }
    // If target found, return appropriately
    return nums[begin] == target ? begin : -1; 
}
