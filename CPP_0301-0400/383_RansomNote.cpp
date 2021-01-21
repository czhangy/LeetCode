#include "errors.h"
#include <string>
#include <vector>

using namespace std;

// 383. Ransom Note - Easy - String
// -------------------------------------------------------------
// Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
// Each letter in the magazine string can only be used once in your ransom note.
// -------------------------------------------------------------
// Solve #1 | 07/24/20 | Time: 4:17 | Avg. Runtime: 40.8ms

bool canConstruct(string ransomNote, string magazine) { // O(N + M) time, O(1) space
    // Initialize mock hash table
    vector<int> letters(26, 0);
    // Map all letters in magazine to number of occurrences
    for (char c : magazine)
        letters[c - 'a']++;
    // Check if we have enough letters to contruct ransomNote
    for (char c : ransomNote) {
        // If letter is available, use it
        if (letters[c - 'a'] > 0)
            letters[c - 'a']--;
        // Failure condition
        else
            return false;
    }
    return true;
}
