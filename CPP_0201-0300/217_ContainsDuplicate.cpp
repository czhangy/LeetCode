#include "errors.h"
#include <unordered_set>
#include <vector>

using namespace std;

// 217. Contains Duplicate - Easy - Array/Hash Table
// -------------------------------------------------------------
// Given an array of integers, find if the array contains any duplicates.
// Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
// -------------------------------------------------------------
// Solve #1 | 07/12/20 | Time: 2:23 | Avg. Runtime: 97.6ms

bool containsDuplicate(vector<int> &nums) { // O(N) time, O(N) space
    // Initialize
    int size = nums.size();
    unordered_set<int> hashTable;
    // Iterate through the vector
    for (int i = 0; i < size; i++) {
        // New unique element found --> insert into hash set
        if (hashTable.find(nums[i]) == hashTable.end())
            hashTable.insert(nums[i]);
        // Duplicate found
        else
            return true;
    }
    // Full iteration succeeded --> no duplicates found
    return false;
}
