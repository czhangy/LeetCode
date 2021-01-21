#include "errors.h"
#include <string>
#include <unordered_set>

using namespace std;

// 345. Reverse Vowels Of A String - Easy - Two Pointers/String
// -------------------------------------------------------------
// Write a function that takes a string as input and reverse only the vowels of a string.
// -------------------------------------------------------------
// Solve #2 | 07/21/20 | Time: 3:06 | Avg. Runtime: 23.2ms

string reverseVowels(string s) { // O(N) time, O(1) space
    // Hard-code vowels --> use hash set for fast access
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    // Iterate 2 pointers through the string
    for (int i = 0, j = s.size(); i < j; i++, j--) {
        // Position i at next vowel
        while (i < j && vowels.find(s[i]) == vowels.end())
            i++;
        // Position j at next vowel
        while (i < j && vowels.find(s[j]) == vowels.end())
            j--;
        // Swap
        swap(s[i], s[j]);
    }
    return s;
}
