#include "errors.h"
#include <stack>
#include <string>

using namespace std;

// 20. Valid Parentheses - Easy - String/Stack
// -------------------------------------------------------------
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// - Open brackets must be closed by the same type of brackets.
// - Open brackets must be closed in the correct order.
// -------------------------------------------------------------
// Solve #1 | 06/26/20 | Time: 6:06 | Avg. Runtime: 0ms

bool isValid(string s) { // O(N) time, O(N) space
        // Initialization
        stack<char> openParens;
        int len = s.size();
        // Iterate through string
        for (int i = 0; i < len; i++) {
            switch(s[i]) {
                // Push all opening brackets onto stack
                case '(':
                case '{':
                case '[':
                    openParens.push(s[i]);
                    break;
                // Check for matching open parentheses and remove it
                case ')':
                    if (openParens.empty() || openParens.top() != '(')
                        return false;
                    openParens.pop();
                    break;
                // Check for matching open curly brace and remove it
                case '}':
                    if (openParens.empty() || openParens.top() != '{')
                        return false;
                    openParens.pop();
                    break;
                // Check for matching open square bracket and remove it
                case ']':
                    if (openParens.empty() || openParens.top() != '[')
                        return false;
                    openParens.pop();
                    break;
            }
        }
        // Check to make sure there are no more opening brackets on the stack
        return openParens.empty();
    }
