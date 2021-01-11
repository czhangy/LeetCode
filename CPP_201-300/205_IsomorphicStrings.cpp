#include "errors.h"
#include <string>
#include <unordered_map>

using namespace std;

// 205. Isomorphic Strings - Easy - Hash Table
// -------------------------------------------------------------
// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters.
// No two characters may map to the same character, but a character may map to itself.
// -------------------------------------------------------------
// Solve #1 | 07/11/20 | Time: 12:41 | Avg. Runtime: 24.8ms

bool isIsomorphic(string s, string t) { // O(N) time, O(N) space
    // Catch common case
    if (s.size() != t.size())
        return false;
    // Initialize
    int size = s.size();
    unordered_map<char, char> hashTable, revHash;
    // Iterate through both strings
    for (int i = 0; i < size; i++) {
        // Find current characters in hash maps
        auto iter = hashTable.find(s[i]);
        auto iter2 = revHash.find(t[i]);
        // Insert new mappings
        if (iter == hashTable.end() && iter2 == revHash.end()) {
            hashTable.insert({s[i], t[i]});
            revHash.insert({t[i], s[i]});
        }
        // Catch all violations of isomorphism
        else if (iter == hashTable.end() || iter2 == revHash.end() || iter->second != t[i] || iter2->second != s[i])
            return false;
    }
    // Full iteration --> isomorphism achieved
    return true;
}
