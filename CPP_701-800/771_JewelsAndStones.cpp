#include "errors.h"
#include <string>
#include <unordered_map>

using namespace std;

// 771. Jewels And Stones - Easy - Hash Table
// -------------------------------------------------------------
// You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have.
// Each character in stones is a type of stone you have.
// You want to know how many of the stones you have are also jewels.
// Letters are case sensitive, so "a" is considered a different type of stone from "A".
// -------------------------------------------------------------
// Solve #1 | 09/13/20 | Time: 2:30 | Avg. Runtime: 5.6ms

int numJewelsInStones(string J, string S) { // O(J + S) time, O(S) space
    // Initialize
    unordered_map<char, int> stones;
    int count = 0;
    // Insert all stones into hash map
    for (char c : S)
        stones[c]++;
    // Add jewel/stone count from hash map
    for (char c : J)
        count += stones[c];
    return count;
}
