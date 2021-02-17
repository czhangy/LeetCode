#include "errors.h"
#include <unordered_map>
#include <vector>

using namespace std;

// 1. Two Sum - Easy - Array/Hash Table
// -------------------------------------------------------------
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.
// -------------------------------------------------------------
// Solve #2 | 01/6/21 | Time: 8:30 | Avg. Runtime: 17.6ms

vector<int> twoSum(vector<int> &nums, int target) { // O(N) time, O(N) space
    // Initialize
    unordered_map<int, vector<int>> m;
    int size = nums.size();
    // Push all numbers into the hash map
    for (int i = 0; i < size; i++)
        m[nums[i]].push_back(i);
    // Find solution
    for (int x : nums)
        // Valid combination found
        if (m.count(x) && m.count(target - x)) {
            // Numbers aren't equal --> guaranteed solution
            if (x != target - x)
                return {m[x][0], m[target - x][0]};
            // Numbers are equal --> check that there are multiple occurances of the number
            else if (m[x].size() > 1)
                return {m[x][0], m[x][1]};
        }
    // Needed to compile, should never be returned
    return {};
}