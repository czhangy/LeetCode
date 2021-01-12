#include "errors.h"
#include <vector>

using namespace std;

// 744. Find Smallest Letter Greater Than Target - Easy - Binary Search
// -------------------------------------------------------------
// Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list that is larger than the given target.
// Letters also wrap around.
// For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.
// -------------------------------------------------------------
// Solve #1 | 09/10/20 | Time: 15:54 | Avg. Runtime: 31.2ms

char nextGreatestLetter(vector<char> &letters, char target) { // O(log N) time, O(1) space
    // Initialize bounds
    int firstIndex = 0, endIndex = letters.size();
    // Binary search
    while (firstIndex < endIndex) {
        // Calculate mid index, protecting against overflow
        int midIndex = firstIndex + ((endIndex - firstIndex) >> 1);
        // If mid character is less than target character, move left bound right
        if (letters[midIndex] <= target)
            firstIndex = midIndex + 1;
        // If mid character is greater than target character, move right bound left
        else
            endIndex = midIndex;
    }
    // If the search returned out of bounds, wrap to start of array
    return firstIndex < letters.size() ? letters[firstIndex] : letters[0];
}
