#include "errors.h"
#include <unordered_set>

using namespace std;

// 1. Happy Number - Easy - Hash Table/Math
// -------------------------------------------------------------
// Write an algorithm to determine if a number n is happy.
// A happy number is a number defined by the following process:
// - Starting with any positive integer, replace the number by the sum of the squares of its digits.
// - Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// - Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.
// -------------------------------------------------------------
// Solve #1 | 07/10/20 | Time: 5:52 | Avg. Runtime: 7.2ms

bool isHappy(int n) { // Undefined time complexity, Undefined space complexity
    // Initialize
    unordered_set<int> hashTable;
    // Loop until the number is no longer unique
    while (hashTable.find(n) == hashTable.end()) {
        // Success condition found
        if (n == 1)
            return true;
        // Place number into hash table
        hashTable.insert(n);
        // Break number down into sum of the squares of its digits
        int temp = 0;
        while (n) {
            temp += pow(n % 10, 2);
            n /= 10;
        }
        n = temp;
    }
    // Loop terminated without the number reaching 1, failure condition
    return false;
}