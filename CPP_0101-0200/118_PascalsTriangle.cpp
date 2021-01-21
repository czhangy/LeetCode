#include "errors.h"
#include <vector>

using namespace std;

// 118. Pascal's Triangle - Easy - Array
// -------------------------------------------------------------
// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
// -------------------------------------------------------------
// Solve #1 | 07/04/20 | Time: 17:38 | Avg. Runtime: 3.2ms

vector<vector<int>> generate(int numRows) { // O(N) runtime, O(N) space
    // Initialize
    vector<vector<int>> pt;
    vector<int> prevRow;
    // Catch 0 rows edge case
    if (!numRows)
        return pt;
    // Iteratively generate all rows
    for (int i = 1; i <= numRows; i++) {
        // Initialize
        vector<int> curRow;
        int rowSize = i;
        // Generate current row
        for (int j = 0; j < rowSize; j++) {
            // Set first and last element as 1
            if (!j || j == rowSize - 1)
                curRow.push_back(1);
            // Use previous row to calculate element
            else
                curRow.push_back(prevRow[j - 1] + prevRow[j]);
        }
        // Move forward
        prevRow = curRow;
        pt.push_back(curRow);
    }
    return pt;
}
