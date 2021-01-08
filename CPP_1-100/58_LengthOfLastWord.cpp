#include "errors.h"
#include <string>

using namespace std;

// 58. Length Of Last Word - Easy - String
// -------------------------------------------------------------
// Given a string s consists of some words separated by spaces, return the length of the last word in the string.
// If the last word does not exist, return 0.
// A word is a maximal substring consisting of non-space characters only.
// -------------------------------------------------------------
// Solve #1 | 06/29/20 | Time: 8:17 | Avg. Runtime: 6.4ms

int lengthOfLastWord(string s) {
    // Catch empty string edge case
    if (s == "")
        return 0;
    // Initialize
    int count = 0, backup = 0, len = s.size();
    // Iterate through the string
    for (int i = 0; i < len; i++) {
        // Increment the length of the word
        if (s[i] != ' ')
            count++;
        // If a previous word existed
        else if (count) {
            // Update backup and reset count
            backup = count;
            count = 0;
        }
        else
            // No update to backup, reset count
            count = 0;
    }
    // Check if a final word existed
    return !count ? backup : count;
}
