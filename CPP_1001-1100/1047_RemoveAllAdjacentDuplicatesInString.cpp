#include "errors.h"
#include <stack>
#include <string>

using namespace std;

// 1047. Remove All Adjacent Duplicates In String - Easy - Stack
// -------------------------------------------------------------
// Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.
// We repeatedly make duplicate removals on S until we no longer can.
// Return the final string after all such duplicate removals have been made.
// It is guaranteed the answer is unique.
// -------------------------------------------------------------
// Solve #1 | 01/16/21 | Time: 3:38 | Avg. Runtime: 20ms

string removeDuplicates(string S) { // O(N) time, O(N) space
    // Initialize
    int size = S.size();
    string res;
    stack<char> chars;
    for (int i = 0; i < size; i++) {
        // If duplicate character, perform deletion
        if (!chars.empty() && S[i] == chars.top())
            chars.pop();
        else
            chars.push(S[i]);
    }
    // Build string using contents of stack
    while (!chars.empty()) {
        res += chars.top();
        chars.pop();
    }
    // Account for reversed building of string
    reverse(res.begin(), res.end());
    return res;
}
