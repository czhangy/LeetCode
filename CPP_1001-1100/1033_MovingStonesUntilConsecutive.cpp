#include "errors.h"
#include <algorithm>
#include <vector>

using namespace std;

// 1033. Moving Stones Until Consecutive - Easy - Brainteaser
// -------------------------------------------------------------
// Three stones are on a number line at positions a, b, and c.
// Each turn, you pick up a stone at an endpoint (ie., either the lowest or highest position stone), and move it to an unoccupied position between those endpoints.
// Formally, let's say the stones are currently at positions x, y, z with x < y < z.
// You pick up the stone at either position x or position z, and move that stone to an integer position k, with x < k < z and k != y.
// The game ends when you cannot make any more moves, ie. the stones are in consecutive positions.
// When the game ends, what is the minimum and maximum number of moves that you could have made?
// Return the answer as an length 2 array: answer = [minimum_moves, maximum_moves]
// -------------------------------------------------------------
// Solve #1 | 01/06/21 | Time: 12:22 | Avg. Runtime: 0ms

vector<int> numMovesStones(int a, int b, int c) { // O(1) time, O(1) space
    // Get points in numerical order
    vector<int> points = {a, b, c};
    sort(points.begin(), points.end());
    // Initialize
    int minMoves, maxMoves;
    // Handle consecutive edge case
    if (points[0] == points[1] - 1 && points[1] == points[2] - 1) 
        minMoves = maxMoves = 0;
    // Common case
    else {
        // Minimum will be 1 or 2 based on distribution
        minMoves = points[1] - points[0] <= 2 || points[2] - points[1] <= 2 ? 1 : 2;
        // Maximum will be distance between each point pairing
        maxMoves = (points[1] - points[0] - 1) + (points[2] - points[1] - 1);
    }
    return {minMoves, maxMoves};
}
