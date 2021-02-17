#include "errors.h"
#include <vector>

using namespace std;

// 26. Remove Duplicates From Sorted Array - Easy - Array/Two Pointers
// -------------------------------------------------------------
// Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
// -------------------------------------------------------------
// Solve #2 | 02/16/21 | Time: 20:27 | Avg. Runtime: 5.8ms

int removeDuplicates(vector<int> &nums) { // O(N) time, O(1) space
    // Initialize
    int cur = 0, size = nums.size(), ahead = 0, val = INT_MIN;
    // Iterate through the vector
    while (cur < size) {
        // Position ahead at the next unique value
        while (ahead < size && nums[ahead] <= val)
            ahead++;
        // No more unique values found
        if (ahead == size)
            break;
        // Set the current index to the next unique value
        nums[cur] = nums[ahead];
        // Update and iterate
        val = nums[ahead];
        cur++;
    }
    // Return the number of unique values
    return cur;
}
