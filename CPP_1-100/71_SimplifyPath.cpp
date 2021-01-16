#include "errors.h"
#include <stack>
#include <string>

using namespace std;

// 71. Simplify Path - Medium - String/Stack
// -------------------------------------------------------------
// Given an absolute path for a file (Unix-style), simplify it.
// Or in other words, convert it to the canonical path.
// In a UNIX-style file system, a period '.' refers to the current directory.
// Furthermore, a double period '..' moves the directory up a level.
// Note that the returned canonical path must always begin with a slash '/', and there must be only a single slash '/' between two directory names.
// The last directory name (if it exists) must not end with a trailing '/'.
// Also, the canonical path must be the shortest string representing the absolute path.
// -------------------------------------------------------------
// Solve #1 | 01/15/21 | Time: 16:06 | Avg. Runtime: 5.6ms

string simplifyPath(string path) { // O(N) time, O(N) space
    // Initialize
    stack<string> dirs, revStack;
    int size = path.size();
    string res = "/";
    // Iterate through the string
    for (int i = 0; i < size;) {
        // Initialize current directory
        string cur;
        // Skip the slashes --> accounts for double slashes
        while (i < size && path[i] == '/')
            i++;
        // Get the full string between slashes
        while (i < size && path[i] != '/') {
            cur += path[i];
            i++;
        }
        // If the string was a parent directory
        if (cur == "..") {
            // Take the last directory off the stack, if possible
            if (!dirs.empty())
                dirs.pop();
        // Otherwise, if the string wasn't empty/the current directory, place it on the stack
        } else if (!cur.empty() && cur != ".")
            dirs.push(cur);
    }
    // Correct for reversed placement onto stack
    while (!dirs.empty()) {
        revStack.push(dirs.top());
        dirs.pop();
    }
    // Build canonical path
    while (!revStack.empty()) {
        res += revStack.top();
        revStack.pop();
        if (!revStack.empty())
            res += "/";
    }
    return res;
}
