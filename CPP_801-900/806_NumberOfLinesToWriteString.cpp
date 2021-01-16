#include "errors.h"
#include <string>
#include <vector>

using namespace std;

// 806. Number Of Lines To Write String - Easy - Math
// -------------------------------------------------------------
// You are given a string s of lowercase English letters and an array widths denoting how many pixels wide each lowercase English letter is.
// Specifically, widths[0] is the width of 'a', widths[1] is the width of 'b', and so on.
// You are trying to write s across several lines, where each line is no longer than 100 pixels.
// Starting at the beginning of s, write as many letters on the first line such that the total width does not exceed 100 pixels.
// Then, from where you stopped in s, continue writing as many letters as you can on the second line.
// Continue this process until you have written all of s.
// Return an array result of length 2 where:
// - result[0] is the total number of lines.
// - result[1] is the width of the last line in pixels.
// -------------------------------------------------------------
// Solve #1 | 09/13/20 | Time: 4:03 | Avg. Runtime: 3.2ms

vector<int> numberOfLines(vector<int> &widths, string S) { // O(N) time, O(1) space
    // Initialize
    int curLine = 0, numLines = 1;
    // Iterate through the string
    for (char c : S) {
        // Create a new line if needed
        if (curLine + widths[c - 'a'] > 100) {
            numLines++;
            curLine = 0; // reset current line count
        }
        // Place current character
        curLine += widths[c - 'a'];
    }
    // Return result of iteration in the form of a vector
    return {numLines, curLine};
}
