#include "errors.h"
#include <string>
#include <vector>

using namespace std;

// 14. Longest Common Prefix - Easy - String
// -------------------------------------------------------------
// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".
// -------------------------------------------------------------
// Solve #1 | 06/26/20 | Time: 6:22 | Avg. Runtime: 6.4ms

string longestCommonPrefix(vector<string>& strs) { // O(N) time, O(N) space
    // Handle edge case
    if (strs.empty())
        return "";
    // Initialize
    string prefix = strs[0];
    int size = strs.size();
    // Iterate through all strings
    for (int i = 1; i < size; i++) {
        // Initialize
        string temp;
        string testString = strs[i];
        // Parse through chars, comparing adjacent elements
        for (int j = 0; j < testString.size() && j < prefix.size(); j++) {
            if (testString[j] == prefix[j])
                temp += testString[j];
            else
                break;
        }
        // Reassign prefix to new commonality
        prefix = temp;
    }
    return prefix;
}
