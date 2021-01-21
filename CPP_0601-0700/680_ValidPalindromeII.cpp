#include "errors.h"
#include <string>

using namespace std;

// 680. Valid Palindrome II - Easy - String
// -------------------------------------------------------------
// Given a non-empty string s, you may delete at most one character.
// Judge whether you can make it a palindrome.
// -------------------------------------------------------------
// Solve #1 | 08/27/20 | Time: 5:48 | Avg. Runtime: 192ms

bool validPalindrome(string s) { // O(N) time, O(1) space
    // Initialize
    int size = s.size();
    // Iterate through first half of array
    for (int i = 0; i < size / 2; i++)
        // Palindrome check failed, delete problematic characters and try again
        if (s[i] != s[size - i - 1])
            return lastCheck(s.substr(i + 1, size - 2 * i - 1)) || lastCheck(s.substr(i, size - 2 * i - 1));
    return true;
}

// Handle palindrome check without character deletion
bool lastCheck(string s) {
    // Initialize
    int size = s.size();
    // Iterate through substring
    for (int i = 0; i < size / 2; i++)
        // Palindrome check failed
        if (s[i] != s[size - i - 1])
            return false;
    return true;
}
