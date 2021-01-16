#include "errors.h"
#include <unordered_set>
#include <vector>

using namespace std;

// 970. Powerful Integers - Easy - Hash Table/Math
// -------------------------------------------------------------
// Given two positive integers x and y, an integer is powerful if it is equal to x^i + y^j for some integers i >= 0 and j >= 0.
// Return a list of all powerful integers that have value less than or equal to bound.
// You may return the answer in any order.
// In your answer, each value should occur at most once.
// -------------------------------------------------------------
// Solve #1 | 12/23/20 | Time: 11:40 | Avg. Runtime: 0ms

vector<int> powerfulIntegers(int x, int y, int bound) { // Undefined time complexity, Undefined space complexity
    // Initialize
    vector<int> res;
    unordered_set<int> ints;
    // Handle x and y are 1 edge case
    if (x == 1 && y == 1) {
        // Check bound
        if (bound >= 2)
            res.push_back(2);
        return res;
    }
    // Handle x or y are 1 edge case
    else if (x == 1 || y == 1) {
        // Get the non-1 value
        x = x == 1 ? y : x;
        // Brute force check for values
        for (int val = 1; val <= bound - 1; val *= x)
            res.push_back(val + 1);
        return res;
    }
    // Common case --> iterate through possible x values
    for (int i = 0; pow(x, i) < bound; i++)
        // Iterate through possible y values
        for (int j = 0; pow(y, j) < bound; j++)
            if (pow(x, i) <= bound - pow(y, j))
                // Use set to handle duplicates
                ints.insert(pow(x, i) + pow(y, j));
    // Convert set to vector
    res.assign(ints.begin(), ints.end());
    return res;
}
