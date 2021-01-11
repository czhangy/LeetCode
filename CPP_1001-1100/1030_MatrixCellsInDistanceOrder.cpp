#include "errors.h"
#include <queue>
#include <vector>

using namespace std;

// 1030. Matrix Cells In Distance Order - Easy - Sort
// -------------------------------------------------------------
// We are given a matrix with R rows and C columns has cells with integer coordinates (r, c), where 0 <= r < R and 0 <= c < C.
// Additionally, we are given a cell in that matrix with coordinates (r0, c0).
// Return the coordinates of all cells in the matrix, sorted by their distance from (r0, c0) from smallest distance to largest distance.
// Here, the distance between two cells (r1, c1) and (r2, c2) is the Manhattan distance, |r1 - r2| + |c1 - c2|.
// (You may return the answer in any order that satisfies this condition.)
// -------------------------------------------------------------
// Solve #1 | 01/05/21 | Time: 16:05 | Avg. Runtime: 49.8ms

vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) { // O(R * C) time, O(R * C) space
    // Initialize
    vector<vector<int>> map(R, vector<int>(C, 0)), res;
    queue<pair<int, int>> q;
    // Handle starting point
    q.push({r0, c0});
    map[r0][c0] = 1;
    // While there are still cells to process
    while (!q.empty()) {
        // Handle next point
        pair<int, int> coord = q.front(); 
        q.pop();
        res.push_back({coord.first, coord.second});
        // Discover point above
        if (coord.first > 0 && !map[coord.first - 1][coord.second]) {
            q.push({coord.first - 1, coord.second});
            map[coord.first - 1][coord.second] = 1;
        }
        // Discover point below
        if (coord.first + 1 < R && !map[coord.first + 1][coord.second]) {
            q.push({coord.first + 1, coord.second});
            map[coord.first + 1][coord.second] = 1;
        }
        // Discover point left
        if (coord.second > 0 && !map[coord.first][coord.second - 1]) { 
            q.push({coord.first, coord.second - 1});
            map[coord.first][coord.second - 1] = 1;
        }
        // Discover point right
        if (coord.second + 1 < C && !map[coord.first][coord.second + 1]) { 
            q.push({coord.first, coord.second + 1});
            map[coord.first][coord.second + 1] = 1;
        }
    }
    return res;
}
