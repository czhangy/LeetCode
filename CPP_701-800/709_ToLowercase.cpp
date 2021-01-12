#include "errors.h"
#include <string>

using namespace std;

// 709. To Lowercase - Easy - String
// -------------------------------------------------------------
// Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
// -------------------------------------------------------------
// Solve #1 | 09/07/20 | Time: 5:03 | Avg. Runtime: 0ms

string toLowerCase(string str) { // O(N) time, O(1) space
    // Initialize
    int size = str.size();
    // Iterate through string
    for (int i = 0; i < size; i++)
        // Change uppercase letters to lowercase
        if (isupper(str[i]))
            str[i] = tolower(str[i]);
    return str;
}
