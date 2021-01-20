#include "errors.h"
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// 1078. Occurrences After Bigram - Easy - Hash Table
// -------------------------------------------------------------
// Given words first and second, consider occurrences in some text of the form "first second third", where second comes immediately after first, and third comes immediately after second.
// For each such occurrence, add "third" to the answer, and return the answer.
// -------------------------------------------------------------
// Solve #1 | 01/19/21 | Time: 3:55 | Avg. Runtime: 0ms

vector<string> findOcurrences(string text, string first, string second) { // O(N) time, O(N) space
    // Initialize
    stringstream ss(text);
    string farLast, last, word;
    vector<string> res;
    // Parse through each word in the text
    while (ss >> word) {
        // If last 2 words match first and second, insert current word into result
        if (farLast == first && last == second)
            res.push_back(word);
        // Update the preceding words
        farLast = last;
        last = word;
    }
    return res;
}
