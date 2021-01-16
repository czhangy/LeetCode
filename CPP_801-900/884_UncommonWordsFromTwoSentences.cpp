#include "errors.h"
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 884. Uncommon Words From Two Sentences - Easy - Hash Table
// -------------------------------------------------------------
// We are given two sentences A and B.
// (A sentence is a string of space separated words. Each word consists only of lowercase letters.)
// A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
// Return a list of all uncommon words.
// You may return the list in any order.
// -------------------------------------------------------------
// Solve #1 | 09/18/20 | Time: 5:45 | Avg. Runtime: 4ms

vector<string> uncommonFromSentences(string A, string B) { // O(N) time, O(N) space
    // Initialize
    unordered_map<string, int> words;
    vector<string> res;
    istringstream iss1(A), iss2(B);
    string word;
    // Map all words to their number of occurrences
    while (iss1 >> word)
        words[word]++;
    while (iss2 >> word)
        words[word]++;
    // Iterate through the hash map, pushing all words with exactly 1 occurrence into the result
    for (auto &iter : words)
        if (iter.second == 1)
            res.push_back(iter.first);
    return res;
}
