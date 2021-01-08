#include "errors.h"
#include <vector>

using namespace std;

// 48. Rotate Image - Medium - Array
// -------------------------------------------------------------
// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
// -------------------------------------------------------------
// Solve #1 | 10/04/20 | Time: 34:07 | Avg. Runtime: 0ms

void rotate(vector<vector<int>> &matrix) { // O(N^2) time, O(1) space
    // Initialize
    int ring = 0, n = matrix.size();
    // Iterate to the vertical halfway point
    for (int i = 0; i <= n / 2; i++, ring++)
        // Iterate starting from/until index based on num of rings
        for (int j = ring; j < n - ring - 1; j++) {
            // Get current ring subset
            int prev = matrix[i][j];
            for (int k = 0; k < 4; k++) {
                // Swap the previous value into the next position
                swap(matrix[j][n - i - 1], prev);
                // Move indexes to the next position in the ring subset --> will end up back at original position
                int temp = i;
                i = j;
                j = n - temp - 1;
            }
        }
}
