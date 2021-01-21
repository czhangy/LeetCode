#include "errors.h"
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// 804. Unique Morse Code Words - Easy - String
// -------------------------------------------------------------
// International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.
// Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter.
// For example, "cab" can be written as "-.-..--...", (which is the concatenation "-.-." + ".-" + "-...").
// We'll call such a concatenation, the transformation of a word.
// Return the number of different transformations among all words we have.
// -------------------------------------------------------------
// Solve #1 | 09/13/20 | Time: 4:28 | Avg. Runtime: 8ms

int uniqueMorseRepresentations(vector<string>& words) { // O(N) time, O(N) space
    // Hard-code all morse characters                                                                                                                                                                                                               // O(N) time, O(N) space
    vector<string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}; // hard code morse code translation
    // Initialization
    unordered_set<string> used;
    int count = 0;
    // Iterate through all words
    for (string str : words) {
        // Initialization
        string translate;
        // Index the hard-coded vector to build morse string from standard English
        for (char c : str)
            translate += morse[c - 'a']; 
        // Add morse translation to hash set --> hash set handles duplicates implicitly
        used.insert(translate);
    }
    // Number of unique morse sequences is the size of the hash set
    return used.size();
}