#include "errors.h"
#include <string>
#include <unordered_set>

using namespace std;

// 824. Goat Latin - Easy - String
// -------------------------------------------------------------
// A sentence S is given, composed of words separated by spaces.
// Each word consists of lowercase and uppercase letters only.
// We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin).
// The rules of Goat Latin are as follows:
// - If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
//    - For example, the word 'apple' becomes 'applema'.
// - If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
//    - For example, the word "goat" becomes "oatgma".
// - Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
//    - For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
// Return the final sentence representing the conversion from S to Goat Latin.
// -------------------------------------------------------------
// Solve #1 | 09/14/20 | Time: 6:44 | Avg. Runtime: 3.2ms

string toGoatLatin(string S) { // O(N) time, O(N) space
    // Initialize
    string aIndex = "a", res;
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'}; // hard code vowels for easier search
    int size = S.size();
    // Iterate through sentence
    for (int i = 0; i < size; i++, aIndex += 'a') {
        // Initialize
        string temp;
        // Get current word
        while (i < size && S[i] != ' ') {
            temp += S[i];
            i++;
        }
        // If word starts with vowel
        if (vowels.count(tolower(temp[0])))
            temp += "ma";
        // If word starts with consonant
        else
            temp = temp.substr(1, temp.size() - 1) + temp[0] + "ma";
        // Append 'a' for third rule
        temp += aIndex;
        // Add spaces when necessary
        res += i == size ? temp : temp + ' ';
    }
    return res;
}
