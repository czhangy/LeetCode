#include "errors.h"
#include <vector>

using namespace std;

// 867. Transpose Matrix - Easy - Array
// -------------------------------------------------------------
// Given a matrix A, return the transpose of A.
// The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.
// -------------------------------------------------------------
// Solve #1 | 09/17/20 | Time: 6:21 | Avg. Runtime: 23.2ms

vector<vector<int>> transpose(vector<vector<int>> &A) { // O(N) time, O(N) space
    // Initialize
    vector<vector<int>> res;
    int size1 = A[0].size(), size2 = A.size();
    // Iterate through columns
    for (int i = 0; i < size1; i++) {
        // Initialize
        vector<int> curRow(size2);
        // Iterate through rows
        for (int j = 0; j < size2; j++)
            curRow[j] = A[j][i];
        // Update matrix
        res.push_back(curRow);
    }
    return res;
}
