#include "errors.h"
#include <string>

using namespace std;

// 917. Reverse Only Letters - Easy - String
// -------------------------------------------------------------
// Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.
// -------------------------------------------------------------
// Solve #1 | 09/18/20 | Time: 2:02 | Avg. Runtime: 0ms

string reverseOnlyLetters(string S) { // O(N) time, O(1) space
    // Iterate 2 pointers through the string
    for (int i = 0, j = S.size() - 1; i < j; i++, j--) {
        // Place i at the leftmost letter
        while (i < j && !isalpha(S[i]))
            i++;
        // Place j at the rightmost letter
        while (i < j && !isalpha(S[j]))
            j--;
        // Swap in-place
        swap(S[i], S[j]);
    }
    return S;
}
