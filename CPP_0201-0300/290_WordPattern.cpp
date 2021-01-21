#include "errors.h"
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

// 290. Word Pattern - Easy - Hash Table
// -------------------------------------------------------------
// Given a pattern and a string s, find if s follows the same pattern.
// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.
// -------------------------------------------------------------
// Solve #2 | 07/19/20 | Time: 3:51 | Avg. Runtime: 1.6ms

bool wordPattern(string pattern, string str) { // O(N) time, O(N) space
        // Initialize
        istringstream ss(str);
        string word;
        unordered_map<char, string> hash;
        unordered_map<string, char> revHash;
        // Iterate through the pattern
        for (char c : pattern) {
            // Check if there are any characters remaining in the string
            if (!getline(ss, word, ' '))
                return false;
            // Check string -> pattern mapping
            if (hash.emplace(c, word).first->second != word)
                return false;
            // Check pattern -> string mapping
            if (revHash.emplace(word, c).first->second != c)
                return false;
        }
        // Check if there are no more characters in the string
        return !getline(ss, word, ' ');
    }
