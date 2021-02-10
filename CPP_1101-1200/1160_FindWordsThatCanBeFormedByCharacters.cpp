#include "errors.h"
#include <string>
#include <vector>

using namespace std;

// 1160. Find Words That Can Be Formed By Characters - Easy - Array/Hash Table
// -------------------------------------------------------------
// You are given an array of strings words and a string chars.
// A string is good if it can be formed by characters from chars (each character can only be used once).
// Return the sum of lengths of all good strings in words.
// -------------------------------------------------------------
// Solve #1 | 02/09/21 | Time: 6:37 | Avg. Runtime: 54.4ms

int countCharacters(vector<string> &words, string chars) { // O(N) time, O(1) space
    // Initialize
    int sum = 0;
    vector<int> hashMap(26, 0);
    // Map all usable characters
    for (char c : chars)
        hashMap[c - 'a']++;
    // Iterate through the words
    for (string str : words) {
        // Initialize
        vector<int> temp(hashMap);
        bool flag = true;
        // Iterate through the current string
        for (char c : str)
            // If the current character is unavailable, exit loop
            if (!temp[c - 'a']--) {
                flag = false;
                break;
            }
        // Check if the entire string was iterated through
        sum += flag ? str.size() : 0;
    }
    return sum;
}
