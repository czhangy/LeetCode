#include "errors.h"
#include <stack>
#include <string>

using namespace std;

// 1021. Remove Outermost Parentheses - Easy - Stack
// -------------------------------------------------------------
// A valid parentheses string is either empty (""), "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.
// For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
// A valid parentheses string S is primitive if it is nonempty, and there does not exist a way to split it into S = A+B, with A and B nonempty valid parentheses strings.
// Given a valid parentheses string S, consider its primitive decomposition: S = P_1 + P_2 + ... + P_k, where P_i are primitive valid parentheses strings.
// Return S after removing the outermost parentheses of every primitive string in the primitive decomposition of S.
// -------------------------------------------------------------
// Solve #1 | 12/25/20 | Time: 12:44 | Avg. Runtime: 3.2ms

string removeOuterParentheses(string S) { // O(N) time, O(N) space
    // Intialize
    stack<char> parens;
    int size = S.size();
    string res;
    // Iterate through the string
    for (int i = 0; i < size;) {
        // Push open parentheses without appending the string
        parens.push(S[i]);
        i++;
        // Get current grouping
        while (!parens.empty()) {
            // Open parentheses found
            if (S[i] == '(') {
                parens.push(S[i]);
                res += "(";
            // Closing parentheses found
            } else {
                parens.pop();
                if (!parens.empty())
                    res += ")";
            }
            i++;
        }
    }
    return res;
}
