#include "errors.h"
#include <vector>

using namespace std;

// 59. Spiral Matrix II - Medium - Array
// -------------------------------------------------------------
// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n^2 in spiral order.
// -------------------------------------------------------------
// Solve #1 | 01/04/21 | Time: 11:13 | Avg. Runtime: 0ms

vector<vector<int>> generateMatrix(int n) { // O(N^2) time, O(N^2) space
    // Initialize
    vector<vector<int>> res(n, vector<int>(n));
    int vertical = n - 1, horizontal = n;
    int i = 0, j = 0, rev = 1, val = 1;
    bool h = true;
    // While there are still more spaces to process
    while (vertical || horizontal) {
        // Horizontal handling
        if (h) {
            // Fill row
            for (int k = 0; k < horizontal; k++) {
                res[i][j] = val;
                j += rev;
                val++;
            }
            // Reposition i and j
            j -= rev;
            i += rev;
            // Redirect to horizontal
            h = false;
            // Horizontal distance decreases by 1 every segment
            horizontal--;
        }
        else
        { // vertical handling
            for (int k = 0; k < vertical; k++)
            {
                res[i][j] = val;
                i += rev;
                val++;
            }
            // Reposition i
            i -= rev;
            // Redirect to horizontal
            h = true;
            // Vertical distance decreases by 1 every segment
            vertical--;
            // Handle corners
            rev = rev == 1 ? -1 : 1;
            // Reposition j
            j += rev;
        }
    }
    return res;
}
