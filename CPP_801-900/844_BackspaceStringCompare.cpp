#include "errors.h"
#include <string>

using namespace std;

// 844. Backspace String Compare - Easy - Two Pointers/Stack
// -------------------------------------------------------------
// Given two strings S and T, return if they are equal when both are typed into empty text editors.
// # means a backspace character.
// Note that after backspacing an empty text, the text will continue empty.
// -------------------------------------------------------------
// Solve #4 | 01/05/21 | Time: 25:12 | Avg. Runtime: 0ms

bool backspaceCompare(string S, string T) { // O(N) time, O(1) space
    // Initialize
    int i = S.size() - 1, j = T.size() - 1;
    while (1) {
        // Initialize
        int skip = 0;
        // Handle backspacing in S
        while (i >= 0 && (skip || S[i] == '#')) {
            skip += S[i] == '#' ? 1 : -1;
            i--;
        }
        // Reset skip
        skip = 0;
        // Handle backspacing in T
        while (j >= 0 && (skip || T[j] == '#')) { 
            skip += T[j] == '#' ? 1 : -1;
            j--;
        }
        // Compare current characters
        if (i >= 0 && j >= 0 && S[i] == T[j]) {        
            i--;
            j--;
        // Exit the loop when out of characters or characters don't match
        } else
            break;
    }
    // Check if both strings were successfully processed
    return i == -1 && j == -1;
