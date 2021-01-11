#include "errors.h"
#include <string>
#include <vector>

using namespace std;

// 344. Reverse String - Easy - Two Pointers/String
// -------------------------------------------------------------
// Write a function that reverses a string.
// The input string is given as an array of characters char[].
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
// You may assume all the characters consist of printable ASCII characters.
// -------------------------------------------------------------
// Solve #1 | 07/21/20 | Time: 1:39 | Avg. Runtime: 81.6ms

void reverseString(vector<char> &s) { // O(N) time, O(1) space
    // Iterate 2 pointers through string
    for (int i  = 0, j = s.size() - 1; i < j; i++, j--)
        // Perform swap
        swap(s[i], s[j]);
}
