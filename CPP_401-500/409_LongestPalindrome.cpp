#include "errors.h"
#include <string>
#include <unordered_map>

using namespace std;

// 409. Longest Palindrome - Easy - Hash Table
// -------------------------------------------------------------
// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
// Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
// -------------------------------------------------------------
// Solve #1 | 07/27/20 | Time: 11:38 | Avg. Runtime: 4ms

int longestPalindrome(string s) { // O(N) time, O(N) space
    // Initialize
    unordered_map<char, int> hash;
    int len = 0, odd = 0;
    // Map characters to number of occurrences
    for (char c : s)
        hash[c]++;
    // Iterate through the hash map
    for (auto i : hash) {
        int val = i.second;
        // Account for odd length possibility
        if (!odd && val & 1)
            odd = 1;
        // Build palindrome with even count characters
        if (val >= 2)
            len += val - (val & 1);
    }
    // Account for odd length possibility
    return len + odd;
}
