#include "errors.h"
#include <string>
#include <vector>

using namespace std;

// 1189. Maximum Number Of Balloons - Easy - Hash Table/String
// -------------------------------------------------------------
// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
// You can use each character in text at most once. Return the maximum number of instances that can be formed.
// -------------------------------------------------------------
// Solve #1 | 02/12/21 | Time: 4:06 | Avg. Runtime: 12ms

int maxNumberOfBalloons(string text) { // O(N) time, O(1) space
    // Initialize
    vector<int> chars(26, 0);
    string base = "balloon";
    int count = 0;
    // Iterate through text, mapping each character to its number of occurrences
    for (char c : text)
        chars[c - 'a']++;
    // Iterate through the string balloon
    for (int i = 0; true;) {
        // Current character ran out
        if (!chars[base[i] - 'a']--)
            break;
        // Loop around and increment
        if (i == 6) {
            count++;
            i = 0;
        } else
            i++;
    }
    return count;
}
