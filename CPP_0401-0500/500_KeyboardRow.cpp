#include "errors.h"
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// 500. Keyboard Row - Easy - Hash Table
// -------------------------------------------------------------
// Given a list of words, return the words that can be typed using letters on only one row of an American keyboard.
// -------------------------------------------------------------
// Solve #1 | 08/04/20 | Time: 11:57 | Avg. Runtime: 0.8ms

vector<string> findWords(vector<string> &words) {
    // Hard-code keyboard rows
    unordered_set<char> row1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    unordered_set<char> row2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    unordered_set<char> row3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    // Initialize
    int size = words.size();
    vector<string> res;
    // Iterate through the words
    for (int i = 0; i < size; i++) {
        // Initialize
        char temp = tolower(words[i][0]);
        bool push = true;
        // First character is in row 3
        if (row3.count(temp))
            // Iterate through the current word
            for (int j = 1; j < words[i].size(); j++)
                // Not typable using row 3 characters only
                if (!row3.count(tolower(words[i][j]))) {
                    push = false;
                    break;
                }
        // First character is in row 2
        else if (row2.count(temp))
            // Iterate through the current word
            for (int j = 1; j < words[i].size(); j++)
                // Not typable using row 2 characters only
                if (!row2.count(tolower(words[i][j]))) {
                    push = false;
                    break;
                }
        // First character is in row 1
        else
            // Iterate through the current word
            for (int j = 1; j < words[i].size(); j++)
                // Not typable using row 1 characters only
                if (!row1.count(tolower(words[i][j]))) {
                    push = false;
                    break;
                }
        // Character is typable using 1 row
        if (push)
            res.push_back(words[i]);
    }
    return res;
}
