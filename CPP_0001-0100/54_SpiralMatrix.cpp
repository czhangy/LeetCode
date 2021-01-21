#include "errors.h"
#include <vector>

using namespace std;

// 54. Spiral Matrix - Medium - Array
// -------------------------------------------------------------
// Given an m x n matrix, return all elements of the matrix in spiral order.
// -------------------------------------------------------------
// Solve #2 | 01/04/21 | Time: 7:18 | Avg. Runtime: 0ms

vector<int> spiralOrder(vector<vector<int>> &matrix) { // O(M * N) time, O(M * N) space
    // Initialization
    int m = matrix.size(), n = matrix[0].size(), size = m * n;
    vector<int> res(size);
    int i = 0, j = 0, ind = 0, rev = 1;
    // Vertical distance starts decremented by 1
    m--;
    // Algorithm starts horizontally
    bool h = true;
    // While there are still more spaces to process
    while (ind != size) {
        // Horizontal handling
        if (h) {
            // Get row values
            for (int k = 0; k < n; k++) {
                res[ind] = matrix[i][j];
                j += rev;
                ind++;
            }
            // Adjust for overcorrection
            j -= rev;
            // Horizontal distance decreases by 1 every segment
            n--;
            i += rev;
            // Redirect to vertical
            h = false;
        // Vertical handling
        } else { 
            // Get column values
            for (int k = 0; k < m; k++) {
                res[ind] = matrix[i][j];
                i += rev;
                ind++;
            }
            // Adjust for overcorrection
            i -= rev;
            // Vertical distance decreases by 1 every segment
            m--;
            // Handle corners
            rev = rev == 1 ? -1 : 1;
            j += rev;
            // Redirect to horizontal
            h = true;
        }
    }
    return res;
}
