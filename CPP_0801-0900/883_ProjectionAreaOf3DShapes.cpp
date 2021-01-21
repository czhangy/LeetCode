#include "errors.h"
#include <vector>

using namespace std;

// 883. Projection Area Of 3D Shapes - Easy - Math
// -------------------------------------------------------------
// You are given an n x n grid where we place some 1 x 1 x 1 cubes that are axis-aligned with the x, y, and z axes.
// Each value v = grid[i][j] represents a tower of v cubes placed on top of the cell (i, j).
// We view the projection of these cubes onto the xy, yz, and zx planes.
// A projection is like a shadow, that maps our 3-dimensional figure to a 2-dimensional plane.
// We are viewing the "shadow" when looking at the cubes from the top, the front, and the side.
// Return the total area of all three projections.
// -------------------------------------------------------------
// Solve #1 | 09/18/20 | Time: 13:19 | Avg. Runtime: 15.2ms

int projectionArea(vector<vector<int>> &grid) { // O(N * M) time, O(N) space
    // Initialize
    int xyArea = 0, xzArea = 0, yzArea = 0, size1 = grid.size(), size2 = grid[0].size();
    vector<int> colMax(size2);
    // Iterate through rows
    for (int i = 0; i < size1; i++) {
        // Initialize
        int vecMax = 0;
        // Iterate through columns
        for (int j = 0; j < size2; j++) {
            // Get number of cubes on cell
            int val = grid[i][j];
            // Update x-y area
            if (val)
                xyArea++;
            // Update the maximums
            vecMax = max(val, vecMax);
            colMax[j] = max(colMax[j], val);
        }
        // Update x-z area
        xzArea += vecMax;
    }
    // Find y-z area using accumulated maximums
    for (int val : colMax)
        yzArea += val;
    return xzArea + yzArea + xyArea;
}
