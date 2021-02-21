#include <vector>

using namespace std;

// 136. Single Number - Easy - Hash Table/Bit Manipulation
// -------------------------------------------------------------
// Given a non-empty array of integers nums, every element appears twice except for one.
// Find that single one.
// -------------------------------------------------------------
// Solve #2 | 02/19/21 | Time: 0:43 | Avg. Runtime: 17.6ms

int singleNumber(vector<int> &nums) { // O(N) time, O(1) space
    // Initialize
    int res = 0;
    // XOR each value in the array with each other
    for (int x : nums)
        res ^= x;
    // The only remaining value is the one that wasn't XORed with itself
    return res;
}
