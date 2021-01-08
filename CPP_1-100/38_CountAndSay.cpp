#include "errors.h"
#include <string>

using namespace std;

// 38. Count And Say - Easy - String
// -------------------------------------------------------------
// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
// - countAndSay(1) = "1"
// - countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
// To determine how you "say" a digit string, split it into the minimal number of groups so that each group is a contiguous section all of the same character.
// Then for each group, say the number of characters, then say the character.
// To convert the saying into a digit string, replace the counts with a number and concatenate every saying.
// Given a positive integer n, return the nth term of the count-and-say sequence.
// -------------------------------------------------------------
// Solve #1 | 06/28/20 | Time: 20:15 | Avg. Runtime: 10.4ms

string countAndSay(int n) { // O(N) time, O(N) space
    // Catch n = 1 base case
    if (n == 1)
        return "1";
    // Recursive call
    string translate = countAndSay(n - 1);
    // Initialize
    int size = translate.size();
    string res;
    // Iterate through old string
    for (int i = 0; i < size; i++) {
        // Initialize
        char curChar = translate[i];
        int count = 1;
        // Build result
        while (i + 1 < size && translate[i + 1] == curChar) {
            i++;
            count++;
        }
        res += to_string(count) + curChar;
    }
    return res;
}
