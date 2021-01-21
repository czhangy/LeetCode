#include "errors.h"
#include <vector>

using namespace std;

// 485. Max Consecutive Ones - Easy - Array
// -------------------------------------------------------------
// Given a binary array, find the maximum number of consecutive 1s in this array.
// -------------------------------------------------------------
// Solve #1 | 08/03/20 | Time: 2:07 | Avg. Runtime: 88ms

int findMaxConsecutiveOnes(vector<int> &nums) { // O(N) time, O(1) space
    // Initialize
    int maxi = 0, cur = 0, size = nums.size();
    // Iterate through the array
    for (int num : nums) {
        // Consecutive streak broken, update maximum sequence
        if (!num) {
            maxi = max(maxi, cur);
            cur = 0;
        }
        // Increment current sequence length
        else
            cur++;
    }
    // Account for possibility of remainder sequence
    return max(cur, maxi);
}
