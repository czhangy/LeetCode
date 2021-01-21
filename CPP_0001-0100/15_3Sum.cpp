#include "errors.h"
#include <algorithm>
#include <vector>

using namespace std;

// 15. 3Sum - Medium - Array/Two Pointers
// -------------------------------------------------------------
// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
// Find all unique triplets in the array which gives the sum of zero.
// Notice that the solution set must not contain duplicate triplets.
// -------------------------------------------------------------
// Solve #2 | 09/26/20 | Time: 29:27 | Avg. Runtime: 62.4ms

vector<vector<int>> threeSum(vector<int>& nums) { // O(N^2) time, O(M) space
    // Initialize
    int size = nums.size();
    vector<vector<int>> res;
    // If the vector has less than 3 elements, it's invalid
    if (size < 3)
        return {};
    // Sort to allow for binary search method of 2sum
    sort(nums.begin(), nums.end());
    // Iterate through all nums
    for (int i = 0; i < size - 2; i++) {
        // Assign pivot digit
        int cur = nums[i];          
        // Break when we've iterated past valid section --> sum too large    
        if (cur + nums[i + 1] + nums[i + 2] > 0)
            break;
        // Initialize for binary search
        int lo = i + 1, hi = size - 1;
        // Binary search 2sum
        while (lo < hi) { 
            // Initialize by indexing into array
            int left = nums[lo], right = nums[hi];
            // Valid combination found
            if (!(cur + left + right)) {
                // Push --> must remove duplicate values since each number only has 1 complement
                res.push_back({cur, left, right});
                // Remove duplicates from left
                while (lo < hi && nums[lo] == left) 
                    lo++;
                // Remove duplicates from right
                while (lo < hi && nums[hi] == right) 
                    hi--;
            } else if (cur + left + right > 0)
                // Sum currently too high, pull right bound left
                hi--;
            else
                // Sum currently too low, push left bound
                lo++;
        }
        // Remove duplicates based on pivot digit
        while (i < size - 3 && nums[i + 1] == cur)
            i++;
    }
    return res;
}
