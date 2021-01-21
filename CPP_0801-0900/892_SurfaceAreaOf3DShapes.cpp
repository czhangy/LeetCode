#include "errors.h"
#include <vector>

using namespace std;

// 892. Surface Area Of 3D Shapes - Easy - Math/Geometry
// -------------------------------------------------------------
// You are given an n x n grid where you have placed some 1 x 1 x 1 cubes.
// Each value v = grid[i][j] represents a tower of v cubes placed on top of cell (i, j).
// After placing these cubes, you have decided to glue any directly adjacent cubes to each other, forming several irregular 3D shapes.
// Return the total surface area of the resulting shapes.
// -------------------------------------------------------------
// Solve #2 | 09/19/20 | Time: 8:06 | Avg. Runtime: 20ms

int surfaceArea(vector<vector<int>> &grid) { // O(N^2) time, O(1) space
    // Initialize
    int size1 = grid.size(), size2 = grid[0].size(), sa = 0;
    // Iterate through columns
    for (int i = 0; i < size1; i++)
        // Iterate through rows
        for (int j = 0; j < size2; j++) {
            // Calculate surface area of current stack
            sa += grid[i][j] ? (grid[i][j] << 2) + 2 : 0;
            // Adjust for covered surfaces
            if (i)
                sa -= min(grid[i][j], grid[i - 1][j]) << 1;
            if (j)
                sa -= min(grid[i][j], grid[i][j - 1]) << 1;
        }
    return sa;
}
