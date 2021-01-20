#include "errors.h"
#include <string>

using namespace std;

// 1071. Greatest Common Divisor Of Strings - Easy - String
// -------------------------------------------------------------
// For two strings s and t, we say "t divides s" if and only if s = t + ... + t  (t concatenated with itself 1 or more times).
// Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.
// -------------------------------------------------------------
// Solve #1 | 01/19/21 | Time: 19:28 | Avg. Runtime: 14.4ms

string gcdOfStrings(string str1, string str2) { // O(N^2) time, O(N) space
    // Initialize
    int size1 = str1.size(), size2 = str2.size(), i = 0, j = 0;
    string sub;
    // Ensure str1 is the longer string
    if (size1 < size2) {
        swap(str1, str2);
        swap(size1, size2);
    }
    // Catch equal strings edge case
    else if (size1 == size2)
        return str1 == str2 ? str1 : "";
    // Get the largest substring with common elements
    while (i < size2 && str1[i] == str2[i])
        i++;
    sub = str1.substr(i, size1 - i);
    // Check substring for validity
    while (sub.size()) {
        // Initialize
        string temp = sub;
        // Add to substring until a match is found
        while (temp != str2 && temp.size() < size2)
            temp += sub;
        // If substring is a factor of the shorter string
        if (temp == str2) {
            // Check if substring is a factor of the longer string
            while (temp != str1 && temp.size() < size1)
                temp += sub;
            // Substring is a factor of both strings
            if (temp == str1)
                return sub;
        }
        // Make substring shorter
        sub = sub.substr(0, sub.size() - 1);
    }
    // No common factors found
    return "";
}
