#include "errors.h"
#include <string>
#include <vector>

using namespace std;

// 17. Letter Combinations Of A Phone Number - Medium - String/Backtracking
// -------------------------------------------------------------
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
// Return the answer in any order.
// -------------------------------------------------------------
// Solve #2 | 10/04/20 | Time: 18:37 | Avg. Runtime: 0ms

vector<string> letterCombinations(string digits) { // O(4^N) time, O(4^N) space
    // Hard-code number -> char mappings
    vector<string> mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    // Initialize
    vector<string> res;
    // Catch empty input edge case
    if (digits.size())
        // Begin recursion
        helper(res, mapping, 0, "", digits);
    return res;
}

// Recursive helper function
void helper(vector<string>& res, vector<string> & letters, int index, string cur, string& dig) {
    // If finished with current permutation, push into res vector
    if (index == dig.size()) 
        res.push_back(cur);
    else
        // Iterate through the num -> char mapping
        for (int i = 0; i < letters[dig[index] - '0' - 2].size(); i++)
            // Backtrack using recursive call
            helper(res, letters, index + 1, cur + letters[dig[index] - '0' - 2][i], dig);
}
