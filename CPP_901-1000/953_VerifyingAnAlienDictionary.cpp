#include "errors.h"
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 953. Verifying An Alien Dictionary - Easy - Hash Table
// -------------------------------------------------------------
// In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order.
// The order of the alphabet is some permutation of lowercase letters.
// Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.
// -------------------------------------------------------------
// Solve #1 | 12/23/20 | Time: 14:32 | Avg. Runtime: 5.6ms

bool isAlienSorted(vector<string> &words, string order) { // O(NM) time, O(1) space
    // Initialize
    unordered_map<char, int> dict;
    int size = words.size();
    // Map alien characters to their lexicographic order
    for (int i = 0; i < 26; i++)
        dict[order[i]] = i;
    // Iterate through the vector
    for (int i = 0; i + 1 < size; i++) {
        int size1 = words[i].size(), size2 = words[i + 1].size();
        // Iterate through strings
        for (int j = 0, k = 0; j < size1 && k < size2; j++, k++) {
            // Words are ordered correctly
            if (dict[words[i][j]] < dict[words[i + 1][k]])
                break;
            // Words are not ordered correctly
            else if (dict[words[i][j]] > dict[words[i + 1][k]] || (j + 1 < size1 && k + 1 == size2))
                return false;
        }
    }
    return true;
}
