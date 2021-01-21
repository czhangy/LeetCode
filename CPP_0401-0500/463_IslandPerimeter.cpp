#include "errors.h"
#include <vector>

using namespace std;

// 463. Island Perimeter - Easy - Hash Table
// -------------------------------------------------------------
// You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
// Grid cells are connected horizontally/vertically (not diagonally).
// The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
// The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island.
// One cell is a square with side length 1.
// The grid is rectangular, width and height don't exceed 100.
// Determine the perimeter of the island.
// -------------------------------------------------------------
// Solve #1 | 08/01/20 | Time: 12:28 | Avg. Runtime: 176ms

int islandPerimeter(vector<vector<int>> &grid) {
    // Initialize
    int perim = 0, size1 = grid.size(), size2 = grid[0].size();
    // Iterate through grid rows
    for (int i = 0; i < size1; i++)
        // Iterate through grid columns
        for (int j = 0; j < size2; j++)
            // Increment perimeter if necessary
            if (grid[i][j]) {
                int temp = 4;
                // Check right side
                if (j + 1 < size2 && grid[i][j + 1])
                    temp--;
                // Check left side
                if (j - 1 >= 0 && grid[i][j - 1])
                    temp--;
                // Check below
                if (i + 1 < size1 && grid[i + 1][j])
                    temp--;
                // Check above
                if (i - 1 >= 0 && grid[i - 1][j])
                    temp--;
                perim += temp;
            }
    return perim;
}
