#include "errors.h"
#include <string>
#include <vector>

using namespace std;

// 748. Shortest Completing Word - Easy - Hash Table
// -------------------------------------------------------------
// Given a string licensePlate and an array of strings words, find the shortest completing word in words.
// A completing word is a word that contains all the letters in licensePlate.
// Ignore numbers and spaces in licensePlate, and treat letters as case insensitive.
// If a letter appears more than once in licensePlate, then it must appear in the word the same number of times or more.
// For example, if licensePlate = "aBc 12c", then it contains letters 'a', 'b' (ignoring case), and 'c' twice.
// Possible completing words are "abccdef", "caaacab", and "cbca".
// Return the shortest completing word in words.
// It is guaranteed an answer exists.
// If there are multiple shortest completing words, return the first one that occurs in words.
// -------------------------------------------------------------
// Solve #1 | 09/10/20 | Time: 11:07 | Avg. Runtime: 27.2ms

string shortestCompletingWord(string licensePlate, vector<string> &words) { // O(N + M) time, O(1) space
    // Initialize --> use vector in place of hash map due to known subset
    vector<int> alpha(26);
    int count = 0, minLen = 15, size = words.size();
    string minStr;
    // Iterate through string --> map all characters on license plate as lowercase
    for (int i = 0; i < licensePlate.size(); i++)
        if (isalpha(licensePlate[i])) {
            alpha[tolower(licensePlate[i]) - 'a']++;
            count++;
        }
    // Iterate through vector of words
    for (int i = 0; i < size; i++) {
        // Initialize
        vector<int> temp = alpha;
        int tempCount = count;
        // Iterate through word --> track if it can be formed using the license plate letters
        for (char c : words[i])
            if (temp[c - 'a']) {
                temp[c - 'a']--;
                tempCount--;
            }
        // If the minimum-length string needs to be replaced
        if (!tempCount && words[i].size() < minLen) {
            minLen = words[i].size();
            minStr = words[i];
        }
    }
    return minStr;
}
