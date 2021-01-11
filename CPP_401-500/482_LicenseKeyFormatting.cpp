#include "errors.h"
#include <string>

using namespace std;

// 482. License Key Formatting - Easy - String
// -------------------------------------------------------------
// You are given a license key represented as a string S which consists only alphanumeric character and dashes.
// The string is separated into N+1 groups by N dashes.
// Given a number K, we would want to reformat the strings such that each group contains exactly K characters, except for the first group which could be shorter than K, but still must contain at least one character.
// Furthermore, there must be a dash inserted between two groups and all lowercase letters should be converted to uppercase.
// Given a non-empty string S and a number K, format the string according to the rules described above.
// -------------------------------------------------------------
// Solve #1 | 08/02/20 | Time: 9:02 | Avg. Runtime: 50.4ms

string licenseKeyFormatting(string S, int K) { // O(NK) time, O(N) space
    // Initialize
    string str, res;
    // Iterate through the string in reverse order
    for (int i = S.size() - 1; i >= 0; i--) {
        // Build groups
        if (S[i] != '-')
            str += toupper(S[i]);
        // Place hyphens
        if (str.size() == K) {
            res += str + '-';
            str = "";
        }
    }
    // Append any leftover values
    res += str;
    // Account for building the string in reverse
    reverse(res.begin(), res.end());
    // Remove leading hyphens
    while (res[0] == '-')
        res = res.substr(1, res.size() - 1);
    return res;
}
