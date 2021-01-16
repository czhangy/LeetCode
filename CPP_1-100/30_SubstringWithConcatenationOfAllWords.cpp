#include "errors.h"
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 30. Substring With Concatenation Of All Words - Hard - Hash Table/Two Pointers/String
// -------------------------------------------------------------
// You are given a string s and an array of strings words of the same length.
// Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.
// You can return the answer in any order.
// -------------------------------------------------------------
// Solve #1 | 01/15/21 | Time: 15:01 | Avg. Runtime: 660ms

vector<int> findSubstring(string s, vector<string> &words) { // O(SNM^2) time, O(NM) space
    // Initialize
    int size = s.size(), wordSize = words[0].size(), strSize = words.size() * wordSize;
    unordered_map<string, int> st;
    vector<int> res;
    // Map all strings in words to number of occurrences
    for (string str : words)
        st[str]++;
    // Iterate through the string
    for (int i = 0; i < size - strSize + 1; i++) {
        // Initialize
        unordered_map<string, int> temp(st);
        int j;
        // Iterate through the potential substring
        for (j = i; j < i + strSize;) {
            // Get the next word to evaluate
            string word = s.substr(j, wordSize);
            // If the word is not in the remaining substring, exit loop
            if (!temp[word])
                break;
            // Mark the word as used and move on
            else {
                temp[word]--;
                j += wordSize;
            }
        }
        // If all words were used, save the starting index
        if (j == i + strSize)
            res.push_back(i);
    }
    return res;
}
