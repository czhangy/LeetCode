#include "errors.h"
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// 874. Walking Robot Simulation - Easy - Greedy
// -------------------------------------------------------------
// A robot on an infinite XY-plane starts at point (0, 0) and faces north.
// The robot can receive one of three possible types of commands:
// - -2: turn left 90 degrees,
// - -1: turn right 90 degrees, or
// - 1 <= k <= 9: move forward k units.
// Some of the grid squares are obstacles.
// The ith obstacle is at grid point obstacles[i] = (xi, yi).
// If the robot would try to move onto them, the robot stays on the previous grid square instead (but still continues following the rest of the route).
// Return the maximum Euclidean distance that the robot will be from the origin squared (i.e. if the distance is 5, return 25).
// -------------------------------------------------------------
// Solve #2 | 09/19/20 | Time: 9:16 | Avg. Runtime: 327.2ms

int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) { // O(N) time, O(M) space
    // Initialize
    unordered_set<string> obsSearch;
    int dir = 0, res = 0, x = 0, y = 0;
    // Translate obstacles into string format for search
    for (int i = 0; i < obstacles.size(); i++)
        obsSearch.insert(to_string(obstacles[i][0]) + "x" + to_string(obstacles[i][1]));
    // Hard-code directions
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    // Iterate through commands
    for (int command : commands) {
        switch (command) {
        // Turn left
        case -2:
            dir--;
            // Account for looping
            if (dir < 0)
                dir = 3;
            break;
        // Turn right
        case -1:
            dir++;
            // Account for looping
            if (dir > 3)
                dir = 0;
            break;\
        // Move forward
        default:
            // Take steps
            while (command) { 
                // If moving onto obstacle, stop moving
                if (obsSearch.count(to_string(x + dirs[dir][0]) + "x" + to_string(y + dirs[dir][1])))
                    break;
                // Move forward using dir to index
                else {
                    x += dirs[dir][0];
                    y += dirs[dir][1];
                }
                command--;
            }
        }
        // Update the maximum Euclidean distance
        res = max(res, x * x + y * y);
    }
    return res;
}
