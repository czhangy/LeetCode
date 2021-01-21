#include "errors.h"
#include <vector>

using namespace std;

// 766. Toeplitz Matrix - Easy - Array
// -------------------------------------------------------------
// Given an m x n matrix, return true if the matrix is Toeplitz.
// Otherwise, return false.
// A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.
// -------------------------------------------------------------
// Solve #1 | 09/13/20 | Time: 13:54 | Avg. Runtime: 29.6ms

bool isToeplitzMatrix(vector<vector<int>> &matrix) { // O(M * N) time, O(1) space
    // Initialize
    int size1 = matrix.size(), size2 = matrix[0].size();
    // Iteratively check upper right triangle
    for (int i = 0; i < size2; i++) { 
        // Initialize
        int x = 1, val = matrix[0][i];
        // Iterate diagonally until index(es) invalid
        while (x < size1 && x + i < size2) {
            // Mismatch found
            if (matrix[x][x + i] != val)
                return false;
            x++;
        }
    }
    // Iteratively check bottom left triangle   
    for (int i = 1; i < size1; i++) {
        // Initialize
        int x = 1, val = matrix[i][0];
        // Switch x + i to index through rows rather than columns
        while (x + i < size1 && x < size2) { 
            if (matrix[x + i][x] != val)
                return false;
            x++;
        }
    }
    return true;
}
