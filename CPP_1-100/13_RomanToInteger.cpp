#include "errors.h"
#include <string>
#include <unordered_map>

using namespace std;

// 13. Roman To Integer - Easy - Math/String
// -------------------------------------------------------------
// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
// Roman numerals are usually written largest to smallest from left to right.
// However, the numeral for four is not IIII.
// Instead, the number four is written as IV.
// Because the one is before the five we subtract it making four.
// The same principle applies to the number nine, which is written as IX.
// There are six instances where subtraction is used:
// - I can be placed before V (5) and X (10) to make 4 and 9.
// - X can be placed before L (50) and C (100) to make 40 and 90.
// - C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer.
// -------------------------------------------------------------
// Solve #1 | 06/26/20 | Time: N/A | Avg. Runtime: 6.4ms

int romanToInt(string s) { // O(N) time, O(1) space
    // Hard-code numeral --> int associations
    unordered_map<char, int> nums = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    // Initialize
    int sum = nums[s.back()];
    // Build integer
    for (int i = s.length() - 2; i >= 0; --i)
    {
        // Account for prefix behavior
        if (nums[s[i]] < nums[s[i + 1]]) {
            sum -= nums[s[i]];
        } else {
            sum += nums[s[i]];
        }
    }
    return sum;
}
