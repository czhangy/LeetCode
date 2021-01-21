#include "errors.h"
#include <vector>

using namespace std;

// 73. Set Matrix Zeroes - Medium - Array
// -------------------------------------------------------------
// Given an m x n matrix.
// If an element is 0, set its entire row and column to 0.
// Do it in-place.
// -------------------------------------------------------------
// Solve #1 | 01/16/21 | Time: 19:56 | Avg. Runtime: 10.4ms

void setZeroes(vector<vector<int>> &matrix) { // O(N^2) time, O(1) space
    // Initialize
    int size1 = matrix.size(), size2 = matrix[0].size();
    bool zeroRow = false, zeroCol = false;
    // Get information about first row
    for (int i = 0; i < size1; i++)
        if (!matrix[i][0])
            zeroCol = true;
    // Get information about first column
    for (int i = 0; i < size2; i++)
        if (!matrix[0][i])
            zeroRow = true;
    // Iterate through the matrix --> use the first row and column to store all 0 information
    for (int i = 1; i < size1; i++)
        for (int j = 1; j < size2; j++)
            if (!matrix[i][j]) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
    // Use stored information to set zeroes in rows
    for (int i = 1; i < size1; i++)
        if (!matrix[i][0])
            for (int j = 1; j < size2; j++)
                matrix[i][j] = 0;
    // Use stored information to set zeroes in columns
    for (int i = 1; i < size2; i++)
        if (!matrix[0][i])
            for (int j = 1; j < size1; j++)
                matrix[j][i] = 0;
    // Set first row and column according to initial checks
    if (zeroRow)
        for (int i = 0; i < size2; i++)
            matrix[0][i] = 0;
    if (zeroCol)
        for (int i = 0; i < size1; i++)
            matrix[i][0] = 0;
}
