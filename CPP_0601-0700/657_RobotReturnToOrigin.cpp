#include "errors.h"
#include <string>

using namespace std;

// 657. Robot Return To Origin - Easy - String
// -------------------------------------------------------------
// There is a robot starting at position (0, 0), the origin, on a 2D plane.
// Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.
// The move sequence is represented by a string, and the character moves[i] represents its ith move.
// Valid moves are R (right), L (left), U (up), and D (down).
// If the robot returns to the origin after it finishes all of its moves, return true.
// Otherwise, return false.
// The way that the robot is "facing" is irrelevant.
// "R" will always make the robot move to the right once, "L" will always make it move left, etc.
// Also, assume that the magnitude of the robot's movement is the same for each move.
// -------------------------------------------------------------
// Solve #1 | 08/24/20 | Time: 2:32 | Avg. Runtime: 27.2ms

bool judgeCircle(string moves) { // O(N) time, O(1) space
    // Initialize
    int v = 0, h = 0;
    // Iterate through string
    for (char c : moves) {
        switch (c) {
        // Move robot up
        case 'U':
            v++;
            break;
        // Move robot down
        case 'D':
            v--;
            break;
        // Move robot left
        case 'L':
            h++;
            break;
        // Move robot right
        case 'R':
            h--;
            break;
        }
    }
    // Check if all vertical moves cancel and all horizontal moves cancel
    return !v && !h;
}
